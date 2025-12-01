#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int l,r;
	cin>>l>>r;
	vector<int>a,b;
	while(l)
	{
		a.push_back(l%3);
		l/=3;
	}
	while(r)
	{
		b.push_back(r%3);
		r/=3;
	}
	while(a.size()<b.size()) a.push_back(0);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int pref=0;
	int i=0;
	while(i<b.size()&&a[i]==b[i])
	{
		pref+=b[i]+1;
		i++;
	}
	int ans=0;
	while(i<b.size())
	{
		//只有这种情况最高位不算有效位 
		if(i==0&&b[i]==1) ans=max(ans,pref+3*((int)b.size()-i-1));
		//算有效位 
		else ans=max(ans,pref+1+b[i]-1+3*((int)b.size()-i-1));
		pref+=b[i]+1;
		i++;
	}
	cout<<max(pref,ans)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
