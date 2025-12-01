#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>cnt(m,0);
    vector<int>dp(m,0);
    for(int i=0;i<m;i++) 
    {
        cnt[i]=n/m;
        if(i>=1&&i<=n%m) cnt[i]++;
    }
    int ans=ksm(2,cnt[0]);
    // for(int i=0;i<m;i++) cout<<dp[i]<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}