#include <bits/stdc++.h>
using namespace std;
int n,a[200010],mx,t;
void solve()
{
	mx=1;
	cin>>n>>t;
    t=min(t,n-1);
	for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=a[1];
    for(int i=n+1;i>=n-t+1;i--) mx=max(mx,a[i]); 
	
    for(int i=n+1;i>=n-t+1;i--) 
	{
		if(a[i]==mx)
		{
			cout<<n+1-i<<"\n";
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
