#include <bits/stdc++.h>
using namespace std;
int n,k,a[200010];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int cnt=1;
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<=k) cnt++;
        else 
        {
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    ans=max(ans,cnt);
    cout<<n-ans<<"\n";
    // for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
