#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,a[100010];
string s;
void solve()
{
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>s;
	int j=0,i=1,ans=0;
	while(j<s.size())
	{
		if(s[j]=='R'&&i<n) i++;
		if(s[j]=='L'&&i>1) i--;
        ans+=a[i];
        ans%=P;
		j++;
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
