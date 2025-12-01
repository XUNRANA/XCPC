#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(2*(i+2*j)==a+b*2)
			{
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

