#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
void solve()
{
	int n;
	cin>>n;
	int idx;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) idx=i;
	}
	
	if(__gcd(a[1],a[n])==1)
	{
		cout<<"1\n1 "<<n<<"\n";
	}
	else
	{
		cout<<"2\n1 "<<idx<<" "<<n<<"\n";
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
