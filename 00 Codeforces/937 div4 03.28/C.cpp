#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b;
	string s;
	cin>>s;
	a=(s[0]-'0')*10+(s[1]-'0');
	b=(s[3]-'0')*10+(s[4]-'0');
	
	if(a<12) 
	{
		if(a==0) s[0]='1',s[1]='2';
		cout<<s<<" AM\n";
	}
	else 
	{
		if(a>12)
		{
			
		a-=12;
		s[0]=a/10+'0';
		s[1]=a%10+'0';
		}
		cout<<s<<" PM\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
