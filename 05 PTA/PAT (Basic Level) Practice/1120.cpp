#include <bits/stdc++.h>
using namespace std;

int n,s,a[10010];
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ss=0;
	int ans=0;
	for(int i=1,j=1;i<=n;i++) 
	{
		ss+=a[i];
		while(ss>s)
		{
			ss-=a[j];
			j++;
		}
		ans+=i-j+1;
	}
	cout<<ans<<"\n";
    
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
