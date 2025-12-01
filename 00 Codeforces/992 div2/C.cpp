#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxv=__lg(1000000000000ll)+1;
int ans[200010];
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n<=maxv&&k>(1ll<<(n-1)))
    {
        cout<<"-1\n";
        return ;
    }
    int l=1,r=n;
    for(int i=1;i<n;i++)
    {
        if(n-1-i>maxv||k<=(1ll<<(n-i-1)))
        {
            ans[l]=i;
            l++;
        }
        else
        {
            k-=1ll<<(n-i-1);
            ans[r]=i;
            r--;
        }
    }
    ans[l]=n;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}
//4 8
//5 16
//6 32
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
