#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int ans[9][2];
void solve()
{
    string s;
    cin>>s;
    int n=0;
    for(auto i:s)
    {
        n^=1;
        int t=i-'0';
        t%=9;
        for(int j=0;j<9;j++) ans[j][n]=(ans[j][n^1]+ans[(j-t+9)%9][n^1])%P;
        ans[t][n]=(ans[t][n]+1)%P;
    }
    cout<<ans[0][n]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
