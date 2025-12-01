#include <bits/stdc++.h>
using namespace std;


string a[1010];
string b[1010];
int x[1010];
int y[1010];
int mx[21];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) mx[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>x[i]>>y[i];
		mx[x[i]]=max(mx[x[i]],y[i]);
	}
	
	for(int i=1;i<=n;i++) 
	{
		if(mx[x[i]]==-1) continue;
		if(mx[x[i]]==y[i])
		{
			cout<<a[i]<<" "<<b[i]<<" "<<x[i]<<" "<<y[i]<<"\n";
			mx[x[i]]=-1;
		}
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
