#include <bits/stdc++.h>
using namespace std;

int a[810][810];
int is[2000];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++) is[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			is[a[i][j]]=1;
		}
	}
	vector<int>p;
	for(int i=1;i<=2*n;i++) if(!is[i]) p.push_back(i);
	
	for(int i=1;i<=n;i++) p.push_back(a[i][1]);
	for(int i=2;i<=n;i++) p.push_back(a[n][i]);
	for(auto i:p) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
