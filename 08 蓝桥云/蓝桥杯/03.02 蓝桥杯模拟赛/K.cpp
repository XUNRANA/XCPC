#include<bits/stdc++.h>
using namespace std;
int n,m,e[10010],v[10010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>e[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>v[i];
	
	int i=1,j=1;
	while(i<=n&&j<=m)
	{
		while(i<=n&&j<=m&&v[j]<e[i]) j++;
		if(i<=n&&j<=m)
		{
			i++;
			j++;
		}
	}
	cout<<i-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
