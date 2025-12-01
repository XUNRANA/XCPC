#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010];
void solve()
{
	int n;
	cin>>n;
	int i=1,j=n;
	int k=n;
	a[j--]=k--;
	while(i<=j)
	{
		if(i<=j) a[i++]=k--;

		if(i<=j) a[i++]=k--;
		
		if(i<=j) a[j--]=k--;
		
		if(i<=j) a[j--]=k--;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
