#include <bits/stdc++.h>
using namespace std;
int x,ans,y;
void solve()
{
	cin>>x;
	ans=0;
	for(int i=1;i<x;i++) 
	{
		if(__gcd(i,x)+i>ans)
		{
			ans=__gcd(i,x)+i;
			y=i;
		}
	}
	cout<<y<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
