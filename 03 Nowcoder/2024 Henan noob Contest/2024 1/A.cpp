#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,cnt=0;
	cin>>n;
	while(n)
	{
		cnt++;
		if(n&1) n--;
		else n=min(n/2,n-2);
	}
	cout<<cnt<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
