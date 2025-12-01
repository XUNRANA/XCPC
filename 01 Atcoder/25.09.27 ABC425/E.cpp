#include <bits/stdc++.h>
using namespace std;
#define int long long
int P,n,s;
int c[300010];
int C[5010][5010];
void init()
{

    for(int i=0;i<=5000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j) C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
        }
    }
}
void solve()
{
    cin>>n;
    s=0;
    for(int i=1;i<=n;i++) cin>>c[i],s+=c[i];

    int ans=1;
    for(int i=1;i<=n;i++) 
    {
        ans=ans*C[s][c[i]]%P;
        s-=c[i];
    }

    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T>>P;
    init();
	while(T--) solve();
}
