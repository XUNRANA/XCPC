#include <bits/stdc++.h>
using namespace std;
int n,a[300010];
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=i;
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++) a[i]=min(a[i-1]-1,a[i]);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
