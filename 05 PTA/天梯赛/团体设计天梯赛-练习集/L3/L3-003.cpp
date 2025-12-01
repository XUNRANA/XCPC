#include <bits/stdc++.h>
using namespace std;

int n,k,x,fa[2010];
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	fa[fu]=fv;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1000;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		while(k--)
		{
			scanf("%d",&x);
			merge(i,n+x);
		}
	} 
	map<int,int>mp;
	for(int i=1;i<=n;i++) mp[find(i)]++;
	vector<int>a;
	for(auto i:mp) a.push_back(i.second);
	sort(a.begin(),a.end(),greater<int>());
	int f=0;
	cout<<mp.size()<<"\n";
	for(auto i:a)
	{
		if(f) cout<<" ";
		cout<<i;
		f=1;
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}


