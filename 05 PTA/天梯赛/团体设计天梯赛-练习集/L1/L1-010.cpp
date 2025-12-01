#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	vector<int>a;
	for(int i=1;i<=3;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	cout<<a[0]<<"->"<<a[1]<<"->"<<a[2];
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

