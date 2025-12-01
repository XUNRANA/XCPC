#include <bits/stdc++.h>
using namespace std;
void solve()
{
/*
5
0110101
01020102
0000021111
1012121010
0100202010
*/
	string s;
	cin>>s;
	int n=s.size();
	for(int i=1;i<n;i+=2) 
	if(s[i]=='0') s[i]='1';
	else if(s[i]=='1') s[i]='0';
	
	int c0=0,c1=0,c2=0;
	for(auto i:s) if(i=='0') c0++;
	else if(i=='1') c1++;
	else c2++;
	
	int d=abs(c0-c1);
	
	if(c2>=d)
	{
		if((c2+d)&1) cout<<1<<"\n";
		else cout<<"0\n";
	}
	else cout<<d-c2<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
