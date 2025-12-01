#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	bool color=0;//³õÊ¼ÑÕÉ«È«0 
	int fa=-1;
	int val;
	vector<int>son;
};
int n,f,u,v,ans;
int cnt[100];
void mark(int root,vector<node>&p)
{
	if(p[root].color||p[root].fa==-1) return ;
	cnt[root]++;
	p[root].color=1;
	for(auto i:p[root].son)
	{
		if(i==p[root].fa) continue; 
		if(p[i].fa!=-1&&p[i].fa!=root) 
		{
			f=0;
			return ;
		}
		p[i].fa=root;
		mark(i,p);
	}
}
void solve()
{
	cin>>n;
	f=1;
	ans=0;
	vector<node>p(n+5);
	for(int i=1;i<=n;i++) cin>>p[i].val;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		if(p[u].val*2<p[v].val)
		{
			if(p[v].fa!=-1) f=0;
			p[v].fa=u;
		}
		if(p[v].val*2<p[u].val)
		{
			if(p[u].fa!=-1) f=0;
			p[u].fa=v;
		}
		p[u].son.push_back(v);
		p[v].son.push_back(u);
	} 
	for(int i=1;i<=n;i++) mark(i,p);
	for(int i=1;i<=n;i++) ans+=(p[i].color==0);
	if(f==0) cout<<0<<"\n";
	else cout<<ans<<"\n";
	for(int i=0;i<10;i++) cout<<cnt[i]<<" ";
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--) solve();
}
