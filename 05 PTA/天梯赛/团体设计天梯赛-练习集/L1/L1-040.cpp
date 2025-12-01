#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		char ch;
		double h;
		cin>>ch>>h;
		if(ch=='M') printf("%.2f\n",h/1.09);
		else printf("%.2f\n",h*1.09);
	}
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

