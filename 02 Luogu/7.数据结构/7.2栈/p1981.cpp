#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	long long n=0,m=0,ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i])) n=n*10+s[i]-'0';
		else if(s[i]=='+') ans=(ans+n)%10000,n=0;
		else 
		{
			i++;
			m=0;
			while(i<s.size()&&isdigit(s[i])) m=m*10+s[i++]-'0';
			n=n*m%10000;
			i--;
		}
	}
	ans=(ans+n)%10000;
	cout<<ans;
}
