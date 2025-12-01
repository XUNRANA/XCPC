#include <bits/stdc++.h>
using namespace std;
#define int long long

int lowbit(int x)
{
	return x&-x;
}
int is(int x)
{
	int t=sqrt(x);
	return t*t==x;
}
void solve()
{
	int n;
	cin>>n;
	vector<int>ans;
	while(!is(n))
	{
		ans.push_back(lowbit(n));
		n+=lowbit(n);
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}