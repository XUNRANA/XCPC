#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int f=0,a=0;
		if(count(s.begin(),s.end(),'.')!=3||s[0]=='.'||s[s.size()-1]=='.') f=1;
        if(f) continue;
		for(int i=0;i<s.size();i++) 
		if(s[i]=='.'&&(s[i-1]=='.'||s[i+1]=='.')) f=1;
		for(auto i:s)
		{
			if(i=='.') 
			{
				if(a>=256) f=1;
				a=0;
			}
			else a=a*10+i-'0';
		}
		if(a>=256) f=1;
		if(f==0) ans++;
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
