#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int cnt=0,pre=0,t;
	while(n--)
	{
		cin>>t;
		if(pre) 
		{
			if(t==pre+1||t==pre-1); 
			else cnt++;
		}
		pre=t;
	}
	cout<<cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
