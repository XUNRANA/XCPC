#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,s,ans;
void solve()
{
	cin>>n;
    if(n==1) 
    {
        cout<<"1\n";
        return ;
    }
	for(int i=1;i<=n;i++) cin>>t,s+=t;
	for(int i=1;i*i<=s;i++)
	if(s%i==0)
	{
		if(s/i>=n) ans++;
		if(s/i!=i&&i>=n) ans++;
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
