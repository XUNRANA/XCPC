#include <bits/stdc++.h>
using namespace std;


void solve()
{
	string a;
	int d;
	cin>>a>>d;
	int n=a.size();
	string b=a.substr(n-d,d)+a.substr(0,n-d);
	printf("%.2f",stoi(b)*1.0/stoi(a));
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
