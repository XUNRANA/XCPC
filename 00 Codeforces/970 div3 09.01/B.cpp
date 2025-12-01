#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
bool ck(int x)
{
	int t=sqrt(x),x1=0,y=0;
	if(t*t!=x) return 0;
	for(auto i:s)
	{
		if(x1==0||x1==t-1||y==0||y==t-1) 
		{
			if(i=='0') return 0;
		}
		else if(i=='1') return 0;
		y++;
		if(y==t) 
		{
			x1++;
			y=0;
		}
	}
	return 1;
}
void solve()
{

	cin>>n>>s;
	if(ck(n)) cout<<"Yes\n";
	else cout<<"No\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

