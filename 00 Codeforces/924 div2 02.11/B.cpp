#include <bits/stdc++.h>
using namespace std;
int n,a[200010],mx;
void solve()
{
	mx=1;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int j=2;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) a[j++]=a[i];
	
	int i1=2,i=1;
	for(int i1=2,i=1;i1<=j-1;)
	{
		if(a[i1]-a[i]+1<=n) mx=max(i1-i+1,mx),i1++;
		else i++;
	}
	cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
