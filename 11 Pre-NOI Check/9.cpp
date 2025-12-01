#include <bits/stdc++.h>
using namespace std;
int phi(int n)//Å·À­º¯Êý 
{
	int res=n;
	for(int p=2;p*p<=n;p++)
	{
		if(n%p==0)
		{
			while(n%p==0) n/=p;
			res-=res/p;
		}
	}
	if(n>1) res-=res/n;
	return res;
}
//abbabba

void solve()
{
	for(int i=1;i<=10;i++)
	{
		if(phi(i)-1==i-2)
		{
			cout<<i<<"\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
