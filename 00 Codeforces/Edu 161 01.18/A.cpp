#include <bits/stdc++.h>
using namespace std;
long long t,n,f;
int main()
{
	cin>>t;
	while(t--)
	{
		f=0;
		string a,b,c;
		cin>>n>>a>>b>>c;
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i]&&islower(a[i])&&c[i]!=a[i]) f=1;
			if(a[i]==b[i]&&isupper(a[i])&&islower(c[i])) f=1;
			if(a[i]!=b[i]&&islower(c[i])&&c[i]!=tolower(a[i])&&c[i]!=tolower(b[i])) f=1;
		}
		if(f==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
} 
