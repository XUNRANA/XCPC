#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	string a,b;
	cin>>n>>m>>a>>b;
	int j=0;
	for(auto i:b)
	{
		if(j<n&&i==a[j]) j++;
	}
	cout<<j<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
