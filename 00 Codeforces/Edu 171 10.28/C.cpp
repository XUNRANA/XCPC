#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	int n;
	cin>>n>>s;
	long long ans=0;
	queue<int>q;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='1')
		{
			q.push(i);
		}
		else 
		{
			ans+=i+1;
			if(!q.empty()) q.pop();
		}
	}
	int t=(q.size()+1)/2; 
	while(!q.empty())
	{
		if(q.size()<=t) ans+=q.front()+1;
		q.pop();
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
