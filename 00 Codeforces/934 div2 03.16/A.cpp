#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k<n-1) cout<<n<<"\n";
		else cout<<1<<"\n";
	}
}
