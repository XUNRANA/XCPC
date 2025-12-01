#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	int l=1,r=1,add=0;
	while(n--)
	{
		char o1,o2;
		int x1,x2;
		cin>>o1>>x1>>o2>>x2;
		if(o1=='+'&&o2=='+') add+=x1+x2;
		else if(o1=='+'&&o2=='x')
		{
			r+=add;
			add=x1+r*(x2-1);
		}
		else if(o1=='x'&&o2=='+')
		{
			l+=add;
			add=x2+l*(x1-1);
		}
		else
		{
			if(x1==x2)
			{
				add+=(l+r+add)*(x1-1);
			}
			else if(x1<x2)
			{
				r+=add;
				add=l*(x1-1)+r*(x2-1);
			}
			else
			{
				l+=add;
				add=l*(x1-1)+r*(x2-1);
			}
		}
	}
	cout<<l+r+add<<"\n";
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

