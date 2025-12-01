#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int m,d,c;
	cin>>m>>d>>c;
	int x;
	
	if(m<6) x=1800;
	else if(m==6) 
	{
		if(d<=20) x=1800;
		else x=2000;
	}
	else if(m==7)
	{
		if(d<=11) x=2000;
		else x=-1;	
	}
	else x=-1;
	if(x==-1) cout<<"Too late!\n";
	else if(c<x) cout<<"Need more!\n";
	else if(c>x) cout<<"^_^\n";
	else cout<<"Ok!\n";
//	cout<<x<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
