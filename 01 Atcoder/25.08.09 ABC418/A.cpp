#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    if(s.size()>=3&&s.substr(s.size()-3)=="tea") cout<<"Yes\n";
    else cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

