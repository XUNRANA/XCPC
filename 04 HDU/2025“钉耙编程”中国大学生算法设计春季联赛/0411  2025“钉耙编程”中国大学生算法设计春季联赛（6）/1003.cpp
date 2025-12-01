#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int a[200010];
int b[200010];
int c[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=a[i]+b[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        int s=a[j];
        j++;
        while(c[j]==c[i]) 
        {
            s+=a[j];
            j++;
        }
        ans=max(ans,s*(j-i));
        i=j-1;
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}