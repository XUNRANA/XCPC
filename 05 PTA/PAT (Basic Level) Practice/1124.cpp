#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	vector<int>a;
	int f=0,s=1;
	a.push_back(0);
	a.push_back(1);
	while(f+s<=1e9)
	{
		int t=f+s;
		a.push_back(t);
		f=s;
		s=t;
	}
	int n;
	cin>>n;
	auto it=upper_bound(a.begin(),a.end(),n);
	auto it0=it--;
	if(n-(*it)<=(*it0)-n) cout<<*it<<"\n";
	else cout<<*it0<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
