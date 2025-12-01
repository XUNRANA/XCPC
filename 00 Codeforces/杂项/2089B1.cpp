#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[400010],b[400010];
int pa[400010];
int pb[400010];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],b[i+n]=b[i];
    for(int i=1;i<=2*n;i++) 
    {
        pa[i]=pa[i-1]+a[i];
        pb[i]=pb[i-1]+b[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(pa[j]-pa[i-1]>pb[j]-pb[i-1])
        {
            j++;
        }
        ans=max(ans,j-i+1);
        i=j;
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


