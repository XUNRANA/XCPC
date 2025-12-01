#include <bits/stdc++.h>
using namespace std;
string f1(string a,string b)
{
	string c;
	if(a.size()>b.size()) swap(a,b);
	c.resize(b.size()+1,'0');
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=a.size();i<b.size();i++) a+='0';
	for(int i=0;i<b.size();i++)
	{
		int t=(c[i]-'0'+a[i]-'0'+b[i]-'0')%10;
		int t1=(c[i]-'0'+a[i]-'0'+b[i]-'0')/10;
		c[i]=t+'0';
		c[i+1]+=t1;
	}
	reverse(c.begin(),c.end());
	if(c[0]=='0') c.erase(c.begin());
	return c;
}
int main()
{
	string a,b,c;
	cin>>a>>b;
	c=f1(a,b);
	cout<<c;
} 
