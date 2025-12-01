#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	for(auto i:s)
	{
		if(i=='A'||i=='E'||i=='I'||i=='O'||i=='U') cout<<i;
		else if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') cout<<char(toupper(i));
		else cout<<char(tolower(i));
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
