#include <bits/stdc++.h>
using namespace std;
int x,y,t,a,b,c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>x>>y>>t>>a>>b>>c;
	if(x<=t) printf("%.6f\n",1.0*(100-x)/c);
	else printf("%.6f",min(1.0*(100-x)/b,1.0*(x-t)/y+1.0*(100-t)/c));
} 
