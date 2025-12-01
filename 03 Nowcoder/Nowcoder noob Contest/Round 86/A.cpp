#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,c,d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		if(1.0*a/(a+b)>1.0*c/(c+d)) cout<<"S\n";
		else cout<<"Y\n";
	}
	
} 