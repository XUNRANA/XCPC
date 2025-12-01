#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,x,y,ans,a,b,la,lb;
int f(int x)
{
	return sqrt(2*x)+1.5;
}
signed main()
{
//	for(int i=1;i<=100;i++) cout<<i<<" "<<f(i)<<" "<<i+f(i)<<'\n';
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if(x>=y) ans=x-y;
		else
		{
			a=f(x);
			b=f(y);
			la=a*(a-1)/2-x;
			lb=b*(b-1)/2-y;
		//	cout<<a<<" "<<la<<" "<<b<<" "<<lb<<"\n";
			if(la<=lb) ans=f(y)-f(x)+lb-la;
			else ans=f(y)+lb-la;
		}
		cout<<ans<<"\n";
	} 
}
