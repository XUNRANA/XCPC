#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[110][110];
void solve()
{
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
	{
		char ch;
		cin>>ch;
		a[i][j]=(ch=='1');
        cnt+=(ch=='0');
	}
	
	vector<array<int,4>>ans;
	if(cnt&1) cout<<"-1\n";
    else
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=m;j++)
    		if(!a[i][j]&&j+1<=m)
    		{
    			a[i][j]^=1;
    			a[i][j+1]^=1;
    			ans.push_back({i,j,i,j+1});
			}
		}
		for(int i=1;i<=n;i++)
		if(!a[i][m]&&i+1<=n)
		{
			a[i][m]^=1;
			a[i+1][m]^=1;
			ans.push_back({i,m,i+1,m});
		}
		cout<<ans.size()<<"\n";
		for(auto i:ans) 
		{
			for(auto j:i) cout<<j<<" ";
			cout<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
