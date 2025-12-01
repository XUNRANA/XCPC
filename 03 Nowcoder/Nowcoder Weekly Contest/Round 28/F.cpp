#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010],ans;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
    vector<int>dp;
    dp.push_back(0);
    for(int i=1;i<=n;i++)
    {
        ans+=upper_bound(dp.begin(),dp.end(),a[i]-k)-dp.begin();
        dp.insert(upper_bound(dp.begin(),dp.end(),a[i]),a[i]);        
    }
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

