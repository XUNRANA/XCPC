#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int c1=count(s.begin(),s.end(),'-');
	int c0=count(s.begin(),s.end(),'_');
	cout<<c1/2*(c1-c1/2)*c0<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
