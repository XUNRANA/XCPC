#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s,a[100005];
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll temp=s;
	ll cnt=1;
	while(temp)
	{
		if(temp&1) cnt++;
		cnt++;
		temp/=2;
	}
	cout<<cnt<<"\n";
	cout<<"1 1 1 /\n";
	while(s)
	{
		if(s&1) cout<<n+1<<" "<<n+1<<" 1 +\n";	
		s/=2;
		cout<<"1 1 1 +\n";
	}
}