#include <bits/stdc++.h>
using namespace std;
int t,n,a[200010],ans,g;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				g=0;
				for(int j=i+1;j<=n;j++) g=__gcd(g,abs(a[j]-a[j-i]));
				ans+=(g!=1);
			}
		}
		cout<<ans<<"\n";
	}
}
