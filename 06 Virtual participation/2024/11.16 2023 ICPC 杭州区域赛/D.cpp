#include <bits/stdc++.h>
using namespace std;
int n,ans[200010];
void solve()
{
	cin>>n;
	for(int i=2;i<=2*n;i+=2) 
	{
		ans[i]=2;
		ans[i+1]=-1; 
	}
	ans[2*n]=1;
	ans[1]=2*(n-1)-1;
	for(int i=1;i<=2*n;i++) cout<<ans[i]<<" ";
	cout<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
