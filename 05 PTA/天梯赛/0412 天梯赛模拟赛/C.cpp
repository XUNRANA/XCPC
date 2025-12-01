#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
	if(x<=100) 
	{
		if(x%10==0) x-=10;
		else x-=x%10;
	}
	else x=100;
	printf("Gong xi nin! Nin de ti zhong yue wei: %d duo jin\n",x);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
