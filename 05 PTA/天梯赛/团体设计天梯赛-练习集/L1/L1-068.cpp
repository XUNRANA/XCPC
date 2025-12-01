#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	double s=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		s+=1.0/x;
//		cout<<1.0/x<<"\n";
	}
	printf("%.2f",n/s);
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

