#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b,c;
	cin>>a>>b;
	int f=0,f1=0;
	if(b.size()>a.size()) swap(a,b),f=1;
	for(int i=b.size();i<a.size();i++) b='0'+b;
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]-b[i]>=0) 
		{
			if(a[i]-b[i]!=0) f1=1;
			c+=a[i]-b[i]+'0';
		}
		else
		{
			if(a[i]-b[i]!=0) f1=1;
			c+=a[i]-b[i]+10+'0';
			a[i-1]--;
		}
	}
	if(f1==0) 
	{
		cout<<0;
		return 0;
	}
	if(f==1) cout<<"-";
	int l=c.size()-1;
	while(c[l]=='0') l--;
	while(l>=0) cout<<c[l--];
} 
