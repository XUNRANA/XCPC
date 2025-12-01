#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r;
int ck(int mid)
{
	fflush(stdout);
	cout<<"? "<<mid<<" "<<r<<"\n\n";
	int t;
	cout.flush();
	cin>>t;
	if(t!=(mid+1)*(r+1)) return 1;
	return 0;
}
void solve()
{
	l=2,r=999;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m)) l=m+1;
		else r=m-1;
	}
	cout<<"! "<<l<<"\n";
 
}
signed main()
{
 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
