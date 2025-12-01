#include <bits/stdc++.h>
using namespace std;
double dis(double a,double b,double c,double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve()
{
	int a,b,c,d,a1,b1,c1,d1;
	double rx,ry,rx1,ry1;
	cin>>a>>b>>c>>d;
	rx=1.0*(a+c)/2;
	ry=1.0*(b+d)/2;
	cin>>a1>>b1>>c1>>d1;
	rx1=1.0*(a1+c1)/2;
	ry1=1.0*(b1+d1)/2;
	printf("%.10f\n",abs(rx-rx1)+abs(ry-ry1)-sqrt(2)*dis(a1,b1,c1,d1)/2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
