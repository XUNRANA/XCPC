#include <bits/stdc++.h>
using namespace std;
long long t,n;
string s,p;
int main()
{
	cin>>t;
	map<char,char>m;
	m['a']=m['e']='V';
	m['b']=m['c']=m['d']='C';
	while(t--)
	{
		cin>>n>>s;
		p="";
		for(int i=0;i<n;i++) p+=m[s[i]];
		for(int i=0;i<n;i++)
		{
			cout<<s[i];
			if(p[i]=='V'&&i+1<n&&p[i+1]=='C'&&i+2<n&&p[i+2]=='V') cout<<".";
			if(p[i]=='C'&&i+1<n&&p[i+1]=='C') cout<<".";
		}
		cout<<"\n";
	}
}
