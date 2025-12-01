#include <bits/stdc++.h>
using namespace std;
int n,m,t,k,p,i;
struct st
{
	int l,r,f;
}s[100010];
int main()
{
	s[0].r=1;
	s[0].l=1;
	s[1].r=0;
	s[1].l=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		cin>>k>>p;
		if(p==0)
		{
			s[s[k].l].r=i;
			s[i].l=s[k].l;
			
			s[i].r=k;
			s[k].l=i;
		}
		else
		{
			s[s[k].r].l=i;
			s[i].r=s[k].r;
			
			s[i].l=k;
			s[k].r=i;
		}
	}
	cin>>m;
	while(m--)
	{
		cin>>t;
		s[t].f=1;
	}
	i=0;
	while(s[i].r!=0)
	{
		i=s[i].r;
		if(!s[i].f) cout<<i<<" ";
	}
}
