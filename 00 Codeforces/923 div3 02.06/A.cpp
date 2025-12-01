#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	cout<<s.rfind('B')-s.find('B')+1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
