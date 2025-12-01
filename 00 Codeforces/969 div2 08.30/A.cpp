#include <bits/stdc++.h>
using namespace std;
int l,r,cnt;
void solve()
{
	cin>>l>>r;
	cnt=0;
	for(int i=l;i<=r;i++) if(i&1) cnt++;
	cout<<cnt/2<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
