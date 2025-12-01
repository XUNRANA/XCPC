#include <bits/stdc++.h>
using namespace std;
int n,a[110],b[2200],k,j,fx,f;
void solve()
{
	fx=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=0;i--)
	{
		k=1;
		for(j=1;j<=i;j++)
		{
			if(a[j]<10) b[k++]=a[j];
			else b[k++]=a[j]/10,b[k++]=a[j]%10;
		}
		for(;j<=n;j++) b[k++]=a[j];
		f=0;
		for(j=1;j<=k-2;j++) if(b[j]>b[j+1]) f=1;
		if(f==0) fx=1;
	}
	if(fx==1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
