#include <bits/stdc++.h>
using namespace std;
int main()
{
	int M,D,y,m,d;
	cin>>M>>D>>y>>m>>d;
	if(d+1>D) 
	{
		d=d+1-D;
		if(m+1>M)
		{
			m=m+1-M;
			y++;
		}
		else m=m+1;
	}
	else d=d+1;
	cout<<y<<" "<<m<<" "<<d;	
} 
