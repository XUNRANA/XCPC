#include <bits/stdc++.h>
using namespace std;
int n,a[110][110];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=n;j++) swap(a[i][j],a[n-i+1][j]);
    }
    for(int j=1;j<=n/2;j++)
    {
        for(int i=1;i<=n;i++) swap(a[i][j],a[i][n-j+1]);
    }
    for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
