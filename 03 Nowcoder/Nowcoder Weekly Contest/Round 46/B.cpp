#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,mx,cnt,a[100010];
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(x==i) continue;
        if(a[i]>mx)
        {
            mx=a[i];
            cnt=1;
        }
        else if(a[i]==mx) cnt++;
    }
    cout<<cnt<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
