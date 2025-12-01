#include <bits/stdc++.h>
using namespace std;
void solve()
{
	double p;
	cin>>p;
	printf("%.6f",p*p*(1-p)*(1-p));
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
