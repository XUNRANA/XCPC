#include <bits/stdc++.h>
using namespace std;
int n,k,a[100010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1||k>n) 
	{
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=k/2;i++) swap(a[i],a[k-i+1]);
	if(k&1) swap(a[k/2+1],a[k/2]);
	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
