#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp;
void init()
{
	for(int i=1;i<=6;i++)
	for(int j=1;j<=6;j++)
	for(int k=1;k<=6;k++)
	{
		int ca=0,cb=0;
		if(i==1||i==4) ca+=i;
		else cb+=i;
		
		if(j==1||j==4) ca+=j;
		else cb+=j;
		
		if(k==1||k==4) ca+=k;
		else cb+=k;
		
		mp[{ca,cb}]=1;
	}
}
void solve()
{
	int a,b;
	cin>>a>>b;
	if(mp.count({a,b})) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
