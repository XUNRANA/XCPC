#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) 
    {
        cout<<"YES\n";
        return ;
    }
	if(n&1)
	{
        int cnt=0;
        for(int i=n-1;i>=2;i-=2)
        {
            cnt+=max(0ll,(a[i+1]-(a[i]+i*cnt))/i);
            a[i]+=cnt*i;
            a[i-1]+=cnt*(i-1);
        }
        for(int i=2;i<=n;i++) 
        if(a[i-1]>a[i])
        {
            cout<<"NO\n";
            return ;
        }
        cout<<"YES\n";
	}
	else cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
