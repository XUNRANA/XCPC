#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,c1,c2;
	string s;
	cin>>t;
	while(t--)
	{
		c1=c2=0;
		cin>>n>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='-') c1++;
			else c2++;
		}
		cout<<abs(c1-c2)<<"\n";
    }
}
