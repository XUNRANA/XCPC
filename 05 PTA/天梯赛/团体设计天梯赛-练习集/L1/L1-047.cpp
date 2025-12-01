#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		string name;
		int x,y;
		cin>>name>>x>>y;
		if(x<15||x>20||y<50||y>70) cout<<name<<"\n";
		
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

