#include <bits/stdc++.h>
using namespace std;
#define N 4010
#define P 998244353
#define int long long
int C[N][N],ans;
int n,m,t,s;
void init()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		if(!j) C[i][j]=1;
		else C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		s+=t;
	}
    
	if(s>m) cout<<"0\n";
	else if(s==m) cout<<"1\n";
	else 
    {
        for(int i=0;i<=m-s;i++) ans=(ans+C[i+n-1][n-1])%P;
        cout<<ans<<"\n";
    }
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
