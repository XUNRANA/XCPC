#include <bits/stdc++.h>
using namespace std;
int n,k,l,r,a[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>l>>r;
		a[l]++;
		a[r+1]--;
	}
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	sort(a+1,a+1+n);
	if(n&1) cout<<a[(n+1)/2]<<"\n";
	else cout<<(a[n/2]+a[n/2+1])<<"\n";
}
