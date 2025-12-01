#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
void solve()
{
    int n,ans;
	cin>>n;
	ans=(20+(4*n+1)%P*(2*n-4)%P*3%P+(n*n%P+4*n%P-3+P)%P*(n*n%P-4*n%P+4+P)%P*2%P)%P;
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
