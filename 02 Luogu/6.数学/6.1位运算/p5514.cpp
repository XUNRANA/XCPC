#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans,t;
	cin>>n;
	ans=0;
	while(n--)
	{
		cin>>t;
		ans^=t;
	}
	cout<<ans;
}
