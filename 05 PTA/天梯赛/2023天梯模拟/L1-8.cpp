#include <bits/stdc++.h>
using namespace std;

int a[11];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	int j=1;
	while(1)
	{
		string s;
		cin>>s;
		if(s=="End") break;
		if(cnt==-1)
		{
			if(s[0]=='J') cout<<"Bu\n";
			else if(s[0]=='B') cout<<"ChuiZi\n";
			else cout<<"JianDao\n";
		}
		else
		{
			if(s[0]=='C') cout<<"Bu\n";
			else if(s[0]=='J') cout<<"ChuiZi\n";
			else cout<<"JianDao\n";
		}
		cnt++;
		if(cnt==a[j]) 
		{
			j++;
			if(j>n) j-=n;
			cnt=-1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
