#include <bits/stdc++.h>
using namespace std;
int a[9];
void solve()
{
	for(int i=0;i<9;i++) cin>>a[i];
	
	
	for(int i=1;i<9;i++)
	{
		if(i&1) 
		{
			a[i]+=a[i-1]/2;
			a[i-1]%=2;
		}
		else
		{
			a[i]+=a[i-1]/3;
			a[i-1]%=3;
		}
	}
	for(int i=0;i<9;i++) cout<<a[i]<<" \n"[i==8];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
