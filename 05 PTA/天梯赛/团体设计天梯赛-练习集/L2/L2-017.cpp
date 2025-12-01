#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,x;
	cin>>n;
	vector<int>a;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		if(i<n/2) s1+=a[i];
		else s2+=a[i];
	}
	printf("Outgoing #: %lld\nIntroverted #: %lld\nDiff = %lld",n-n/2,n/2,abs(s2-s1));	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

