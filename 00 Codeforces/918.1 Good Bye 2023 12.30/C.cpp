#include <bits/stdc++.h>
using namespace std;
long long t,n,s,co,ce,a[100010];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		s=co=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1) co++;
			s+=a[i];
			if(i==1) cout<<s;
			else if(co%3!=1) cout<<" "<<s-co/3;
			else cout<<" "<<s-co/3-1;
		}
		cout<<"\n";
	}
}
