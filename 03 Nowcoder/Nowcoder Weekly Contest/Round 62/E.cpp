#include <bits/stdc++.h>
using namespace std;
int n,nq,a[100010],ans[100010],B,res,tr[100010],b[100010];
struct node
{
	int l,r,i;
}q[100010];
bool cmp(node q1,node q2)
{
    if (q1.l/B != q2.l/B) return q1.l < q2.l;
    return (q1.l/B & 1) ? (q1.r > q2.r) : (q1.r < q2.r);
	
}

int lowbit(int x)
{
	return x&-x;
}

int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}

void update(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
unordered_map<int,int>mp,mp1;
void add(int x)
{
	update(mp[x],1);
}
void del(int x)
{
	update(mp[x],-1);
}
void solve()
{
	cin>>n>>nq;
	for(int i=1;i<=n;i++) 
    {
        cin>>a[i],b[i]=a[i];
    }
	sort(b+1,b+1+n);
    
	mp[b[1]]=1;
    mp1[1]=b[1];
	
    for(int i=2;i<=n;i++)
	if(b[i]!=b[i-1]) 
    {
        
        mp[b[i]]=mp[b[i-1]]+1; 
        mp1[mp[b[i-1]]+1]=b[i];
        
    }
	B=sqrt(n);
	for(int i=1;i<=nq;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].i=i;
	}
    
	sort(q+1,q+1+nq,cmp);
	for(int i=1,l=1,r=0;i<=nq;i++)
	{
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		int len=(q[i].r-q[i].l+1+1)/2;
		int lf=1,ri=n;
		while(lf<=ri)
		{
			int m=lf+ri>>1;
			if(query(m)>=len) ri=m-1;
			else lf=m+1; 
		}
		ans[q[i].i]=mp1[lf];
	}
	for(int i=1;i<=nq;i++) cout<<ans[i]<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
