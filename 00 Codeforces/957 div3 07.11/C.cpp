#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int a[100010];
void solve()
{
	cin>>n>>m>>k;
	for(int i=n,j=1;i>=k;i--) a[j++]=i;
	for(int i=m,j=n;i>=1;i--) a[j--]=i;
	
	for(int i=n-k+2,j=m+1;i<=n-m+1-1;i++) a[i]=j++;
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
  	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
