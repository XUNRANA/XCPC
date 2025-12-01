#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m,k,x,y;
    cin>>n>>m>>k;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=k+1;i++)
    {
        cin>>x>>y;
        a[x][y]=i;
    }
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
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
