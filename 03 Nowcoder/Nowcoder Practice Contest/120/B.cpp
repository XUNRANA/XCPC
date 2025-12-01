#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,m,t;
	cin>>t;
	while(t--)
    {
		cin>>a>>b>>c>>m;
		if(m%gcd(a,gcd(b,c))==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}