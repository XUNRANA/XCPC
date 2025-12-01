#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
void solve()
{
    int n,k;
    cin>>n>>c;
    for(int i=1;i<=c;i++) g[i].clear();
    for(int i=1;i<=n;i++) 
    {
        cin>>x;
        g[x].push_back(i);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}