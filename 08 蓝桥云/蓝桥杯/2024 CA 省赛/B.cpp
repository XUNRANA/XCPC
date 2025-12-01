#include <bits/stdc++.h>
using namespace std;
string s0="00000";
string s1="11111";
bool ck(string s)
{
	for(int i=0;i<25;i+=5)
	{
		string t="";
		for(int k=0;k<5;k++) t+=s[i+k];
		if(t==s0||t==s1) return 0;
	}
	
	for(int i=0;i<5;i++)
	{
		string t="";
		for(int k=i;k<25;k+=5) t+=s[k];
		if(t==s0||t==s1) return 0;
	}
	
	string t="";
	for(int i=0;i<5;i++) t+=s[i*6];
	if(t==s0||t==s1) return 0;
	
	t="";
	for(int i=4;i<=20;i+=4) t+=s[i];
	if(t==s0||t==s1) return 0;
	
	
	return 1;
//	0 1 2 3 4
//	5 6 7 8 9
//	10 11 12 13 14
//	15 16 17 18 19
//	20 21 22 23 24
}
void solve()
{

	int ans=0;
	for(int i=1;i<(1<<25);i++) 
	{
		string s;
		int c=0;
		for(int j=24;j>=0;j--)
		{
			if(i>>j&1) s+='1',c++;
			else s+='0';
		}
		if(c==13&&ck(s)) ans++;	
	}
	cout<<ans<<"\n";//3126376
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
