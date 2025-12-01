#include <bits/stdc++.h>
using namespace std;
long long n,s,ans,a[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    ans=s;
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,s-a[i]-a[i-1]+a[i]*a[i-1]);
    }
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
