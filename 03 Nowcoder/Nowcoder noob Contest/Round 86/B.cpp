#include <bits/stdc++.h>
using namespace std;
int t,f,f1;
string a,b;
int main()
{
	cin>>t;
	while(t--)
	{
		f1=0;
		cin>>a>>b;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i=0;i<a.size();i++)
		{
			f=0;
			for(int j=0;j<b.size();j++) if(b[j]==a[i]) f=1;
			if(f==0) f1=1;
		}
		if(f1==1) cout<<"0\n";
		else cout<<"10\n";
	}
} 