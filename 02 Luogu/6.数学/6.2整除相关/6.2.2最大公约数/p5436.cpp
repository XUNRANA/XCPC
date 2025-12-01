#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
        if(n==1) cout<<1<<endl;
		else cout<<n*(n-1)<<endl;	
	}
} 
