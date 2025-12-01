#include <bits/stdc++.h>
using namespace std;
long long t,n,s,a;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		while(n--)
		{
			cin>>a;
			s+=a;
		}
		if((int)sqrt(s)==sqrt(s)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
