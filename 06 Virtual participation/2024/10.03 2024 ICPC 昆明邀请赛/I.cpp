#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=s+s;
	s=" "+s;
	deque<int>dc;
	char a;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			a=s[i];
			cnt=1;
		}
		else if(s[i]==a) cnt++;
		else
		{
			dc.push_back(cnt);
			a=s[i];
			cnt=1;
		}
	}
	if(cnt) dc.push_back(cnt);
	
	int res=0,ans=0;
	for(auto i:dc) res+=i/2;
	
	ans=res;
	for(int i=n+1;i<=2*n;i++)
	{
		if(s[i]==s[i-1])
		{
			int t=dc.back();
			dc.pop_back();
			res-=t/2;
			t++;
			res+=t/2;
			dc.push_back(t);
		}
		else dc.push_back(1);
		
		int t=dc.front();
		dc.pop_front();
		res-=t/2;
		t--;
		res+=t/2;
		if(t) dc.push_front(t);
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
