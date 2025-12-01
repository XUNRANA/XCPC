#include <bits/stdc++.h>
using namespace std;
string f1(string a,int x)
{
	string c;
	int p=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		c+=(a[i]-'0')*x%10+p+'0';
		p=(a[i]-'0')*x/10;
	}
	if(p) c+=p+'0';
	reverse(c.begin(),c.end());
	return c;
}
string f2(string a,string b)
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
	string a,b,c,ans;
	cin>>a>>b;
	if(a.size()<b.size()) swap(a,b); 
	for(int i=b.size()-1;i>=0;i--)
	{
		c=f1(a,b[i]-'0');
		int j=b.size()-1-i;
		while(j--) c+='0';
		ans=f2(c,ans);
	}
	int f=0;
	for(int i=0;i<ans.size();i++) if(ans[i]!='0') f=1;
	if(f==0) cout<<0;
	else cout<<ans;
}
