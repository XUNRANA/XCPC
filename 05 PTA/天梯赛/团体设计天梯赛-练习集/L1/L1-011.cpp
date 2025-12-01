#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string a,b;
	getline(cin,a);
	getline(cin,b); 
	vector<int>f(128,0);
	for(auto i:b) f[i]=1;
	for(auto i:a) if(!f[i]) cout<<i;
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

