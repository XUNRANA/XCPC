#include <bits/stdc++.h>
using namespace std;
long long t,n,k,m,cnt;
void solve()
{
	cnt=0;
	string s,ans;
	cin>>n>>k>>m>>s;
	set<int>s1;
	for(int i=0;i<m;i++)
	{
		s1.insert(s[i]-'a');
		if(s1.size()==k)
		{
			cnt++;
			ans+=s[i];
			s1.clear();
		}
	}
	if(cnt>=n) cout<<"YES\n";
	else 
	{
		cout<<"NO\n";
		m=n-ans.size()-1;
		while(m--) ans+='a';
		if(!s1.empty())
		{
			for(int i=0;i<k;i++)
			if(s1.find(i)==s1.end())
			{
				ans+=i+'a';
				break;
			}
		}
		else ans+='a';
		cout<<ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
}
