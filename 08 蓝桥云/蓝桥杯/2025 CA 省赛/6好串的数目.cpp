#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int cnt=1;
	vector<int>a;
	for(int i=1;i<s.size();i++)
	if(s[i]==s[i-1]||s[i]==s[i-1]+1) cnt++;
	else 
	{
		a.push_back(cnt);
		cnt=1;
	}
	a.push_back(cnt);
	int ans=0;
	int p=0;
//	1 3 5 7
	for(auto i:a)
	{
		ans+=i*(i+1)/2;
		ans+=i*p;
		p=i;
	}
	cout<<ans<<"\n"; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
