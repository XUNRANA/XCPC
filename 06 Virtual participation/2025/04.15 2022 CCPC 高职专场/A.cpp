#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	if(s.substr(0,4)=="CCPC") cout<<"Hello CCPC!";
	else cout<<"This is not my CCPC"; 
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

