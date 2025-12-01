#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int f=-1;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			if(f==-1) f=i;
			cnt++;
		}
	}
	if(cnt<=1) 
	{
		cout<<s<<"\n";
		return ;
	}
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(i==f+cnt-1) ans+='0';
		else ans+='1';
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
