#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=0;
	for(int i=(n+1)/2+1;i<=n;i++) 
	if(a[i]==a[i-1]) ans++;
	else break;
	
	cout<<ans+1<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
