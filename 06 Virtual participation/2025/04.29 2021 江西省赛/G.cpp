#include <bits/stdc++.h>
using namespace std;
int n,m,k,B,c[50010],a[50010];
int ans[50010];
struct node
{
	int l,r,id;
}q[50010];
bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
	return q1.r<q2.r;
}
int cnt[1000010];
int num[1000010];
int maxx;
int f[1000010];
vector<int>p;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e6;i++)
	{
		if(!f[i]) 
        {
            p.push_back(i);
            f[i]=i;
        }
		for(int j=0;j<p.size()&&p[j]*i<=1e6;j++)
		{
			f[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
    // for(int i=1;i<=20;i++) cout<<i<<" "<<f[i]<<"\n";
}

void add(int x)//扩展一个数 
{
    while(x!=1)
    {
        int p=f[x];
        num[cnt[p]]--;//频数--
        cnt[p]++;//次数++
        num[cnt[p]]++;//频数++
        maxx=max(maxx,cnt[p]);
        while(x%p==0) x/=p;
    }
}
void del(int x)//删除一个数 
{
    while(x!=1)
    {
        int p=f[x];
        num[cnt[p]]--;
        if(maxx==cnt[p]&&num[cnt[p]]==0) maxx--;
        cnt[p]--;
        num[cnt[p]]++;
        while(x%p==0) x/=p;
    }
}

void solve()
{
	cin>>n>>m;
	B=sqrt(n);//块的大小 	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
    maxx=0;
    cnt[0]=1;
    int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l) add(a[--l]);//左扩展 
		while(r<q[i].r) add(a[++r]);//右扩展 
		while(l<q[i].l) del(a[l++]);//左删除 
		while(r>q[i].r) del(a[r--]);//右删除 
		ans[q[i].id]=maxx;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
    while(l<=r) del(a[l++]);
}
int main()
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
