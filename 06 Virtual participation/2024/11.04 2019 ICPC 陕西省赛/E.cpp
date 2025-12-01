#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007

int n,k;
string s;
bool ck(int x)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			ans++;
			i+=x-1;
		}
	}
	return ans<=k;
}

void solve()
{
	cin>>n>>k;
	cin>>s;
	int l=1,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
