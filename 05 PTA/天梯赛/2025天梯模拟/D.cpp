#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int cnt=0;
	while(1)
	{
		int x;
		cin>>x;
		if(x==1) cnt++;
		else if(x==0) cout<<cnt<<"\n";
		else break;
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
