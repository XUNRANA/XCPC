#include <bits/stdc++.h>
using namespace std;
unsigned long long n,l,l1;
string s;
int main()
{
	cin>>s>>n;
	l=s.size();
	while(l<n)
	{
		l1=l;
		while(l1<n) l1*=2;
		l1/=2;
		n-=l1+1;
		if(n==0) n=l1;
	}
	cout<<s[n-1];
}
