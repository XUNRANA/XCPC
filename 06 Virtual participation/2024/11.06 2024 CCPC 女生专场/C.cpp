#include <bits/stdc++.h>
using namespace std;
void solve()
{	
	string s;
	cin>>s;
	int c1=0,c2=0;
	for(auto i:s)
	if(i=='C') c1++;
	else if(i=='P') c2++;
	
	if(c1<3||c2<1) cout<<"0\n";
	else
	{
		c1-=3;
		c2-=1;
		cout<<min(c1/2,c2)+1<<"\n";
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
