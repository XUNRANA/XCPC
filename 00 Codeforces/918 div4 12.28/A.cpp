#include <bits/stdc++.h>
using namespace std;
long long t,a,b,c,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(a==b) ans=c;
		else if(a==c) ans=b;
		else if(b==c) ans=a;
		cout<<ans<<"\n";
	}
}
