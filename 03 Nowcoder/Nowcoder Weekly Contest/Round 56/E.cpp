#include <bits/stdc++.h>
using namespace std;
int f[120];
void solve()
{
	int n,m;
	map<string,int>mp;
	cin>>n>>m;
//	00;00-01;59
//	0-119
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		if(s==t) for(int i=0;i<120;i++) f[i]=1;
		else 
		{
			int a=(s[0]-'0')*3600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
			int b=(t[0]-'0')*3600+(t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';
			if(b<a)
            {
                for(int i=a;i<=119;i++) f[i]=1;
                for(int i=0;i<=min(119,b);i++) f[i]=1;
            }
			for(int i=max(0,a);i<=min(119,b);i++) f[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		mp[s]=1;
	}
	int q;
	cin>>q;
	while(q--)
	{
		string t,xt,ct,s;
		cin>>t>>xt>>ct>>s;
		int b=(t[0]-'0')*3600+(t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';
		int x=(xt[0]-'0')*3600+(xt[1]-'0')*60+(xt[3]-'0')*10+xt[4]-'0';
		int c=(ct[0]-'0')*3600+(ct[1]-'0')*60+(ct[3]-'0')*10+ct[4]-'0';
		if(b<120&&f[b]==1)
		{
			if(mp.count(s)&&x<=c) cout<<"Winner xqq\n";
			else cout<<"Joker xqq\n";
		}
		else cout<<"Loser xqq\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

