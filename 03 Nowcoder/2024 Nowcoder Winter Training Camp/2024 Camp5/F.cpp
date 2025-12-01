#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mx,a[100010];
void solve()
{
	cin>>n;
    mx=0;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) mx=max(mx,a[i-1]-a[i]);
    if(n==1) 
    {
        cout<<"0\n";
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
            cout<<"-1\n";
            return ;
        }
        cout<<mx<<"\n";
	}
	else cout<<mx<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
