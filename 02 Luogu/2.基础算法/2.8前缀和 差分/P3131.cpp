#include <bits/stdc++.h>
using namespace std;
int n,ans,a[50010],i,c[7];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],a[i]=(a[i]+a[i-1])%7;
	for(i=1;i<=n;i++)
	if(a[i]==0) ans=max(ans,i); 
	else if(c[a[i]]) ans=max(ans,i-c[a[i]]);
	else c[a[i]]=i;
	cout<<ans;
}
