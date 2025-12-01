#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	if(s=="C"||s=="D"||s=="F"||s=="G"||s=="A") cout<<s<<"#";
	else if(s=="B") cout<<"C";
	else cout<<"F"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
