#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,a[1010][1010];
void solve()
{
	cin>>n>>m>>x;
	if(x==2) cout<<"-1\n";
	else if(x%4==0) a[1][1]=a[1][2]=a[2][1]=a[2][2]=x/4;
	else
	{
		int t=x-6;
		a[1][2]++;
		a[1][3]++;
		a[2][1]++;
		a[2][3]++;
		a[3][1]++;
		a[3][2]++;
		a[n][m]+=t/4;
		a[n][m-1]+=t/4;
		a[n-1][m]+=t/4;
		a[n-1][m-1]+=t/4;
	}
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

