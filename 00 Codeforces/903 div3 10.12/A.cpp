#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n1,n2;
string s1,s2; 
void solve()
{
	c=0;
	cin>>n1>>n2>>s1>>s2;
	while(1) 
	{
		if(s1.find(s2)!=-1) break;
		s1=s1+s1,c++;
		if(s1.size()>1000)
		{
			cout<<"-1\n";
			return ;
		}
	}
	cout<<c<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
