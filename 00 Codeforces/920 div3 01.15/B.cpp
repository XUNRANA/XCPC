#include <bits/stdc++.h>
using namespace std;
long long t,n,c0,c1;
string s1,s2;
int main()
{
	cin>>t;
	while(t--)
	{
		c0=c1=0;
		cin>>n>>s1>>s2;
		for(int i=0;i<n;i++)
		{
			if(s1[i]!=s2[i])
			{
				if(s1[i]=='0') c0++;
				else c1++;
			}
		}
		cout<<max(c0,c1)<<"\n";
	}
}
