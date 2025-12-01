#include <bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		b=c=1e9;
		ans=0;
		cin>>n;
		while(n--)
		{
			cin>>a;
			if(a<=b) b=a;
			else if(a<=c) c=a;
			else b=a,swap(b,c),ans++;
		}
		cout<<ans<<"\n";
	}
}
