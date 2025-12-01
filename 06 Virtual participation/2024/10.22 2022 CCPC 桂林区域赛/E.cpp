#include <bits/stdc++.h>
using namespace std;
#define int long long
int x1,y1,x2,y2;
//Çóax+by==gcd£¨a£¬b£© 
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a; 
	}
	int res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}

void solve()
{
	cin>>x1>>y1>>x2>>y2;
	int dx=x2-x1;
	int dy=y2-y1;
	int u,v;
	//dx*v-dy*u==gcd(dx£¬-dy) 
	exgcd(dx,-dy,v,u);
	cout<<x1+u<<" "<<y1+v<<"\n";	
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
