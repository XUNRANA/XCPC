#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int a[N];
int d[N];
int n,q;
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,mx,mi,add;//维护区间和、还可以维护区间max，min，gcd，等等 
}tr[N<<2];
void pushup(int p)//向上更新 
{
	tr[p].mi=min(tr[lc].mi,tr[rc].mi);
    tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
void pushdown(int p)//向下更新 
{
	if(tr[p].add)
	{
		tr[lc].add+=tr[p].add;
		tr[rc].add+=tr[p].add;

        tr[lc].mi-=tr[p].add;
        tr[lc].mx-=tr[p].add;
       
        tr[rc].mi-=tr[p].add;
        tr[rc].mx-=tr[p].add;
		
        tr[p].add=0;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,d[l],d[l],0};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
int query_mi(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mi;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	pushdown(p);
	int mi=1e18;
	if(x<=m) mi=min(mi,query_mi(lc,x,y));//左子树有部分覆盖 
	if(y>m) mi=min(mi,query_mi(rc,x,y));//右子树有部分覆盖 
	return mi;
}

int query_mx(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mx;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	pushdown(p);
	int mx=-1e18;
	if(x<=m) mx=max(mx,query_mx(lc,x,y));//左子树有部分覆盖 
	if(y>m) mx=max(mx,query_mx(rc,x,y));//右子树有部分覆盖 
	return mx;
}

void updatelr(int p,int x,int y,int k)
{
	if(x<=tr[p].l&&tr[p].r<=y)//覆盖则修改 
	{
		tr[p].mi+=k;
        tr[p].mx+=k;
		tr[p].add+=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//不覆盖裂开 
	pushdown(p);
	if(x<=m) updatelr(lc,x,y,k);
	if(y>m) updatelr(rc,x,y,k);
	pushup(p);	
} 


void solve()
{
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
    d[n]=0;
    build(1,1,n-1);
    cin>>q;
    while(q--)
    {
        int op,l,r,k;
        cin>>op>>l>>r;
        if(op==1) 
        {
            cin>>k;
            updatelr(1,l-1,l-1,k);
            if(r!=n) updatelr(1,r,r,-k);
        }
        else if(op==2) 
        {
            // 全相同
            if(l==r||(query_mi(1,l,r-1)==query_mx(1,l,r-1)&&query_mx(1,l,r-1)==0)) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(op==3)
        {
            //单增

            if(l==r||query_mi(1,l,r-1)>0) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(op==4)
        {
            //单减
            if(l==r||query_mx(1,l,r-1)<0) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(op==5)
        {
            //先增后减
            if(query_mi(1,l,l)<=0||query_mx(1,r-1,r-1)>=0) cout<<"0\n";
            else
            {
                int L=l,R=r-1;
                while(L<=R)
                {
                    int m=L+R>>1;
                    if(query_mi(1,m,m)>0) L=m+1;
                    else R=m-1;
                }
                L--;
                if(query_mi(1,l,L)>0&&query_mx(1,L+1,r-1)<0) cout<<"1\n";
                else cout<<"0\n";
            }  
        }
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}