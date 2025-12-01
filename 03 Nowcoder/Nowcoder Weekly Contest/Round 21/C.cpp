#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,t,a[100010],n,p,x,ans;
void solve()
{
    cin>>n>>p>>x;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    for(int i=1;i<=n;i++)
    {
        int t=x-(s-a[i])%x;
        if(t==x)
        {
            ans+=p/x;
            if(a[i]<=p&&a[i]%x==0) ans--;
        }
        else
        {
            if(a[i]>p)
            {
                ans+=p/x;
                if(p%x>=t) ans++;
            }
            else 
            {
                ans+=p/x;
                if(p%x>=t) ans++;
                if(a[i]%x==t) ans--;
            }
        }
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

