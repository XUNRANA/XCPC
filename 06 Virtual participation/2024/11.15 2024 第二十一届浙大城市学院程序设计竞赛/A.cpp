#include <bits/stdc++.h>  
using namespace std;

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	while(a>0&&c>0)
	{
		a-=d;
		c-=b;
	}
	if(a>0) cout<<"Yes\n";
	else cout<<"No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
