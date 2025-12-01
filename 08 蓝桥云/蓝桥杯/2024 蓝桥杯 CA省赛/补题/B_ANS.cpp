#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[6][6],ans;
string f(int x)
{
	string t;
	for(int i=24;i>=0;i--) t+=(x>>i&1)+'0';
	return t;
}
int ck(int x)
{
	int c=0;
	for(int i=31;i>=0;i--) if(x>>i&1) c++;
	if(c==13)
	{
		string s=f(x);
		s=" "+s;
		if(s.substr(1,5)=="00000"||s.substr(1,5)=="11111") return 0;
		if(s.substr(6,5)=="00000"||s.substr(6,5)=="11111") return 0;
		if(s.substr(11,5)=="00000"||s.substr(11,5)=="11111") return 0;
		if(s.substr(16,5)=="00000"||s.substr(16,5)=="11111") return 0;
		if(s.substr(21,5)=="00000"||s.substr(21,5)=="11111") return 0;
		for(int i=1;i<=5;i++)
		{
			string t="";
			for(int j=i;j<=25;j+=5) t+=s[j];
			if(t=="00000"||t=="11111") return 0;
		}
		string t="";
		for(int i=1,j=1;i<=5;i++)
		{
			t+=s[j];
			j+=6;
		}
		if(t=="00000"||t=="11111") return 0;
		
		t="";
		for(int i=1,j=5;i<=5;i++)
		{
			t+=s[j];
			j+=4;
		}
		if(t=="00000"||t=="11111") return 0;
	
		return 1;
	}
	return 0;
}
signed main()
{
	for(int i=(1<<13);i<=(1<<25)-1;i++)
	{
		if(ck(i)==1)
		{
			ans++;
		}	
	}
	cout<<ans;
}
