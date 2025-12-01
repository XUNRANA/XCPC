#include <bits/stdc++.h>
using namespace std;
string fx(string s)
{
	vector<int>v;
	int s1=0;
	for(auto i:s)
	{
		if(isdigit(i))
		{
			s1=s1*10+i-'0';
		}
		else
		{
			v.push_back(s1);
			s1=0;
		}
	}
	v.push_back(s1);
	
	string p="";
	for(auto i:v)
	{
		for(int j=7;j>=0;j--) 
		if(i>>j&1) p+='1';
		else p+='0';
	}
	return p;
}
void solve()
{
	string str;
	cin>>str;
	int s=0;
	vector<int>v;
	for(auto i:str)
	{
		if(isdigit(i))
		{
			s=s*10+i-'0';
		}
		else
		{
			v.push_back(s);
			s=0;
		}
	}
	string p="";
	for(auto i:v)
	{
		for(int j=7;j>=0;j--) 
		if(i>>j&1) p+='1';
		else p+='0';
	}
/*
192.168.88.0/24
5
10.1.1.1
10.2.3.4
192.168.88.0
192.168.88.88
182.168.0.0

10.0.0.0/16
5
10.0.0.0
10.1.2.3
10.88.88.88
10.0.6.6
172.255.255.255
*/
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		if(fx(str).substr(0,s)==p.substr(0,s)) cout<<"YES\n";
		else cout<<"NO\n";
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
