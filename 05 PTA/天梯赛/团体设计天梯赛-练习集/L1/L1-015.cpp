#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	char ch;
	cin>>n>>ch;
	for(int i=1;i<=(n+1)/2;i++)
	{
		for(int j=1;j<=n;j++) cout<<ch;
		cout<<"\n";
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

