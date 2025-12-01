#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
signed main()
{
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==')') 
		{
			if(s[i-1]=='(') v.push_back(1);
			else v.push_back(2);
		}
	}
	int ans=1;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==2) 
		{
			ans*=(v.size()-i);
			ans%=p;
		}
	} 
	cout<<ans<<'\n';
} 
//(())()
//((()())()())(())
