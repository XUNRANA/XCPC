#include <bits/stdc++.h>
using namespace std;
int x,y,a1,b1,a2,b2;
double dis(int x1,int y1,int x2,int y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void solve()
{
	cin>>x>>y>>a1>>b1>>a2>>b2;
	double d1=max(dis(a1,b1,0,0),dis(a1,b1,x,y));
	double d2=max(dis(a2,b2,0,0),dis(a2,b2,x,y));
	double d3=max({dis(a1,b1,0,0),dis(a2,b2,a1,b1)/2,dis(a2,b2,x,y)});
	double d4=max({dis(a2,b2,0,0),dis(a1,b1,a2,b2)/2,dis(a1,b1,x,y)});
	printf("%.10f\n",min({d1,d2,d3,d4}));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
