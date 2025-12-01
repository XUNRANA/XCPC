#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int w;
	cin>>w;
	if(w<=100)
	{
		if(w%10==0) w-=10;
		else w-=w%10;
	}
	else w=100;
	cout<<"Gong xi nin! Nin de ti zhong yue wei: "<<w<<" duo jin";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
