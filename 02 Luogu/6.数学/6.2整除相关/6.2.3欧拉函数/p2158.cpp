#include <bits/stdc++.h>
using namespace std;
int n,ans,p[400010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=2;i<=n;i++) 
	{
		if(p[i]==i)//i是质数 
		for(int j=i;j<=n;j+=i) p[j]=p[j]*(i-1)/i;//筛i的倍数 
	}
	for(int i=1;i<n;i++) ans+=p[i];
	if(n==1) cout<<"0\n";
	else cout<<(ans<<1|1)<<"\n";
}
