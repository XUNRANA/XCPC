#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cw=0,cl=0;
	string s,t;
	while(1) 
	{
		int f=0;
		cin>>t;
		s+=t;
		for(int i=0;i<t.size();i++) 
		if(t[i]=='E')
		{
			f=1;
			break;
		} 
		if(f==1) break;
	}
	for(int i=0;s[i]!='E';i++)
	{
		if(s[i]=='W') cw++;
		else cl++;
		if((cw>=11||cl>=11)&&abs(cw-cl)>=2)
		{
			cout<<cw<<":"<<cl<<"\n";
			cw=cl=0;
		}
	}
	cout<<cw<<":"<<cl<<"\n\n";
	cw=cl=0;
	for(int i=0;s[i]!='E';i++)
	{
		if(s[i]=='W') cw++;
		else cl++;
		if((cw>=21||cl>=21)&&abs(cw-cl)>=2)
		{
			cout<<cw<<":"<<cl<<"\n";
			cw=cl=0;
		}
	}
	cout<<cw<<":"<<cl;
}
