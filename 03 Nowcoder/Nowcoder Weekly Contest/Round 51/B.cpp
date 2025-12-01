#include <bits/stdc++.h>
using namespace std;
int n,num;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>s;
		for(auto i:s) num+=i-'0';
	}
	if(num%3==0) cout<<"YES\n";
	else cout<<"NO\n";
} 
