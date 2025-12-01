#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,a[200010],b[200010];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	
	for(int i=1;i<=n;i++) if(b[i]!=b[i-1]) a[i]=1;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	while(m--)
	{
		cin>>l>>r;
		if(a[l]==a[l-1]) cout<<a[r]-a[l-1]+1<<"\n";
		else cout<<a[r]-a[l-1]<<"\n";
	}
}