#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int ans=0;
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=5;j++)
		{
			int k=5-i-j;
			if(k>=0) ans=max(ans,(a+i)*(b+j)*(c+k));
		}
	}
	cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
