#include <bits/stdc++.h>
using namespace std;
#define int long long 

double x[10];
double y[10];
double d(int i,int j)
{
	return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
void solve()
{
	for(int i=1;i<=14;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=14;i++)
	{
		printf("[");
		printf("%.3f,%.3f",x[i],y[i]);
//		for(int j=1;j<=14;j++)
//		{
//			printf("%.3f,",d(i,j));
//		}
		printf("],");
		printf("\n");
	}
/*
16.47 96.10
16.47 94.44
20.09 92.54
22.39 93.37
25.23 97.24
22.00 96.05
20.47 97.02
17.20 96.29
16.30 97.38
14.05 98.12
16.53 97.38
21.52 95.59
19.41 97.13
20.09 94.55
*/
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

