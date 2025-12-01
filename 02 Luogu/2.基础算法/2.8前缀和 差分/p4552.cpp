#include <bits/stdc++.h>
using namespace std;
long long n,t,p,s1,s2;
int main()
{
	cin>>n>>p;
	n--;
	while(n--)
	{
		cin>>t;
		if(t-p>0) s1+=t-p;
		else s2-=t-p;
		p=t;
	}
	cout<<max(s1,s2)<<"\n"<<abs(s1-s2)+1;
}
