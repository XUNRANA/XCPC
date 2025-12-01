#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
	cin>>n>>k;
	vector<int>a;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),greater<int>());
	long long s=0;
	for(int i=0;i<min(n,k);i++)
	s+=a[i];
	cout<<s<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
