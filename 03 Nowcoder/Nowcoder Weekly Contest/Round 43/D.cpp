#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,cnt,a[100010],c[100010];

void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
    
	for(int i=1,j=1;j<=n;j++)
	{
		c[a[j]]++;
		if(c[a[j]]==1) cnt++;
		else 
		{
			while(c[a[j]]==2)
			{
				c[a[i]]--;
                if(c[a[i]]==0) cnt--;
				i++;
			}
		}
		if(cnt==k) ans++;
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
