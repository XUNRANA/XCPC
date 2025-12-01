#include <bits/stdc++.h>
using namespace std;
int n,m;
int f[110];
int ans[110];
int s[110];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=m;i++) cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			int k;
			cin>>k;
			if(k==f[j]) ans[i]+=s[j];
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
