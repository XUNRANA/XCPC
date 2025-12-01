#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    if(a[i]==0) cnt++;
    else 
    {
        ans=max(ans,cnt);
        cnt=0;
    }
    ans=max(ans,cnt);
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
