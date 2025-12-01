#include <bits/stdc++.h>
using namespace std;
string s;
int c1,c2;
void solve()
{
	cin>>s;
	c1=c2=0;
	map<int,int>m1,m2; 
	for(auto i:s)
	{
		if(i==')'||i=='(')
		{
			c2=0;
			c1++;
		}
		else 
		{
			c1=0;
			c2++;
		}
		if(c1>1) m1[c1]++;
		if(c2>1) m2[c2]++;
	}
	if(!m1.count(3)&&!m2.count(3)&&m1[2]+m2[2]<=2) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
