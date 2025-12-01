#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>res;
void init()
{
	for(int i=1;i<=1e6;i++) res.push_back(i*(i+1)/2);
}
void solve()
{
	int l,r;
	cin>>l>>r;
	cout<<upper_bound(res.begin(),res.end(),r-l)-res.begin()+1<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

