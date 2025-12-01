#include <bits/stdc++.h>
using namespace std;
long long t,n,f,a1,b,a[200010],d;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>f>>a1>>b;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			d=a[i]-a[i-1];
			if(d*a1>b) f-=b;
			else f-=d*a1;
		}
		if(f<=0) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
