#include <bits/stdc++.h>
using namespace std;
long long x,n,cnt,l=0,r=30,m;
int main()
{
	cin>>x>>n;
	if(x==2)
	{
		if(n==1) cout<<"0\n";
		else if(n==2) cout<<"1\n";
		else cout<<"inf\n";
		return 0;
	}
	double y=log2(x/2.0);
	while(l<=r)
	{
		m=l+r>>1;
		if(y*(1ll<<m)>=n-2) r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}
