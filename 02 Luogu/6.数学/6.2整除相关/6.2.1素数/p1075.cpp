#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans;
	cin>>n;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0) n/=i,ans=i;
	}
	ans=max(ans,n);
	cout<<ans;
}
