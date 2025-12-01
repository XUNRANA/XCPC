#include <bits/stdc++.h>
using namespace std;
int a[100010];
void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
 
	
	for(int i=y;i<=x;i++) a[i]=1;
	for(int i=y-1;i>=1;i--) 
	if(a[i+1]==1) a[i]=-1;
	else a[i]=1;
	for(int i=x+1;i<=n;i++) 
	if(a[i-1]==1) a[i]=-1;
	else a[i]=1;
	
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
