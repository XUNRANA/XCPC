#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int l=-1,r=-1,m=9999999,na=0,x=s.size();
	for(int i=0;i<x;i++)
	{
		if(s[i]=='B')
		{
			l=r;
			r=i;
			m=min(r-l-1,m);
			continue;
		}
		na++;
	}
	m=min(m,x-r-1);
	if(na==x)
	{
		cout<<"0\n";
		return ;
	}
	cout<<na-m<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
