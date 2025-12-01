#include <bits/stdc++.h>
using namespace std;
long long t,n,k,s,t1;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		s=1;
		while(n--)
		{
			cin>>t1;
			s*=t1;
		}
		if(2023%s==0) 
		{
			cout<<"YES\n";
			cout<<2023/s;
			k--;
			while(k--) cout<<" 1";
			cout<<"\n";
		}
		else cout<<"NO\n";
	}
}
