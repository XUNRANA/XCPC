#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n,a[N],fa[N],f[N];
vector<int>g[N];
void init()
{
	g[1].push_back(1);
	for(int i=2;i<=1e6;i++)
	if(!g[i].size()) for(int j=i;j<=1e6;j+=i) g[j].push_back(i);
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n;
	vector<int>res;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(auto j:g[a[i]])
		{
			if(!f[j]) f[j]=i,res.push_back(j);
			else fa[find(i)]=find(f[j]);
 		}
	}
	for(auto i:res) f[i]=0; 
	int cnt=0;
	for(int i=2;i<=n;i++) cnt+=find(1)!=find(i);
	if(!cnt) 
	{
		cout<<"-1 -1\n";
		return ;
	}
	cout<<n-cnt<<" "<<cnt<<"\n";
	for(int i=1;i<=n;i++) if(fa[1]==fa[i]) cout<<a[i]<<" ";
	cout<<"\n";
	
	for(int i=1;i<=n;i++) if(fa[1]!=fa[i]) cout<<a[i]<<" ";
	cout<<"\n";
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
