#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int n,x,y,v[1010]; 
void solve()
{
	cin>>n;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++) v[i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=n;i>=2;i--)
	{
		x=a[1][i];
		v[x]=1;
		for(int j=1;j<=n;j++)
		{
			if(v[a[x][j]]) continue;
			else 
			{
				y=a[x][j];
				break;
			}
		}
		ans.push_back({x,y});
	}
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
signed main()
{
	int t1;
	cin>>t1;
	while(t1--) solve();
}
