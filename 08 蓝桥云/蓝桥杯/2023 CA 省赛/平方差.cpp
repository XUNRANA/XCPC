#include <bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	int l=max(a.size(),b.size());
	while(a.size()<l) a='0'+a;
	while(b.size()<l) b='0'+b;

//	cout<<a<<"\n";
//	cout<<b<<"\n";
	int p=0,t;
	for(int i=l-1;i>=0;i--)
	{
		t=(a[i]-'0'+b[i]-'0'+p)/10;
		a[i]=(a[i]-'0'+b[i]-'0'+p)%10+'0';
		p=t;
	}
//	cout<<a<<"\n";
	if(p) a='1'+a;
	return a;
}
string re(string a,string b)
{
	int f=0,p=0;
	if(a.size()<b.size()) f=1,swap(a,b);
	while(b.size()<a.size()) b='0'+b;
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]>=b[i]) a[i]=a[i]-b[i]+'0';
		else 
		{
			a[i]=a[i]-b[i]+10+'0';
			int i1=i-1;
			while(a[i1]=='0'&&i1>=0) i1--;
			a[i1]--;
			i1++;
			while(i1!=i) a[i1++]='9';
		}
	}
	if(f==1) a[0]='-';
	return a;
}
string m(string a,int b)
{
	int p=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		
	}
}
string mu(string a,string b)
{
	string ans;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			ans=
			
			
		}
	}
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<mu(add(a,b),re(a,b));
}
