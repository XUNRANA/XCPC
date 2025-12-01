#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int b,t1,a1,t2,a2;
	double ans1=0,ans2=0;
	cin>>b>>t1>>a1>>t2>>a2;
	if((t2-t1)*b>=a1) 
	{
		ans1=1.0*a1/b;
		ans2=1.0*a2/b;
	}
	else
	{
		ans1=t2-t1;
		a1-=(t2-t1)*b;
		
		if(a1<a2) 
		{
			ans1+=a1/(0.5*b);
			ans2=1.0*(a2-a1)/b+a1/(0.5*b);
		}
		else
		{
			ans2=a2/(0.5*b);
			ans1+=1.0*(a1-a2)/b+a2/(0.5*b);
		}
	}
	printf("%.9f %.9f\n",ans1,ans2);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
