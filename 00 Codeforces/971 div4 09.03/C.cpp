#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,k;
void solve()
{
	cin>>x>>y>>k;
	int cy=(y+k-1)/k;
	int cx=(x+k-1)/k;
	if(cx==cy||cx==cy+1) cout<<cx+cy<<"\n";
	else if(cx>cy) cout<<2*cx-1<<"\n";
	else cout<<2*max(cx,cy)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
