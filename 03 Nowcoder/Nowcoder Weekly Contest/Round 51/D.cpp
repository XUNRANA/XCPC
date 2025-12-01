#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s>>b;
	a=0;
	for(auto i:s) a=(a*10+i-'0')%b;
	cout<<__gcd(a,b)<<"\n";
	
} 
