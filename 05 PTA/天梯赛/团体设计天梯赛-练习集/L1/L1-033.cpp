#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	set<int>st;
	if(x<1000) st.insert(0);
	while(x)
	{
		st.insert(x%10);
		x/=10;
	}
	return st.size();
}
void solve()
{
	int y,n;
	cin>>y>>n;
	int ans=0;
	while(f(y+ans)!=n) ans++;
	printf("%d %04d",ans,y+ans); 
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

