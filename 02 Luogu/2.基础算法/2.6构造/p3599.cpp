#include <bits/stdc++.h>
using namespace std;
long long x,t,n;
void f1(long long n)
{
	//n必须在第二个 
	
}
void f2(long long n)
{
	//n必须在最后一个 
	
}
int main()
{
	cin>>x>>t;
	while(t--)
	{
		cin>>n;
		cout<<n;
		if(x==1) f1(n);
		else f2(n);
	}
}
