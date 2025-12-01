#include <bits/stdc++.h>
using namespace std;
#define int long long
int ck(int x)
{
	int cnt=0;
	for(int i=30;i>=0;i--) if(x>>i&1) cnt++;
	return cnt;
}
void solve()
{
	int n,k,ans=1e18;
	string s;
	cin>>n>>k>>s;
	int cnt=count(s.begin(),s.end(),'1');
	for(int i=0;i<=k;i++)
	{
		int b=i+cnt,b1=0;
		for(int i=k-1;i>=0;i--) if(b>>i&1) b1+=(1<<i);
		b=b1;
		if(ck(b)==i) ans=min(ans,b);
	}
	if(ans==1e18) cout<<"None\n";
	else 
	{
		for(int i=k-1;i>=0;i--) if(ans>>i&1) cout<<"1";
		else cout<<"0";
		cout<<"\n";
	}
}
signed main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
