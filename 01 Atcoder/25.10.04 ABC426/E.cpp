#include <bits/stdc++.h>
using namespace std;

double dis(array<int,2>a,array<int,2>b)
{
	return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2));
}

double sol(double now)
{
	
}
void solve()
{
	array<int,2>a,a1,b,b1;
	cin>>a[0]>>a[1]>>a1[0]>>a1[1]>>b[0]>>b[1]>>b1[0]>>b1[1];
	if(dis(a,a1)<dis(b,b1)) swap(a,b),swap(a1,b1);
	double d1=dis(a,a1),d2=dis(b,b1); 
	double ans=min(dis(a,b),dis(a1,b1));
	if(!d1)
	{
		printf("%.10f",ans);
		return ;
	}
	double l=0,r=d2;
	ans=min(ans,sol(d2));
	double eps=1e-7;

} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
