#include <bits/stdc++.h>
using namespace std;
int n,m,s,v[110];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<m;j++)
		{
			s++;
			if(s>n) s=1;
			if(v[s]) j--;
		}
		cout<<s<<" ";
		v[s]=1;
	}
} 
