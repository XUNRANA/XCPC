#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	double m,h;
	cin>>m>>h;
    printf("%.1f\n",m/pow(h,2));
	if(m/pow(h,2)>25) puts("PANG");
	else puts("Hai Xing");
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

