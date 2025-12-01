#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,op,x,cnt[30],take;
void solve()
{
	cin>>m;
	while(m--)
	{
		cin>>op>>x;
		if(op==1) cnt[x]++;
		else 
		{
			for(int i=29;i>=0;i--)
			{
				take=min(x>>i,cnt[i]);
				x-=take<<i;
			}
			if(x==0) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T; 
	while(T--) solve();
}