#include <bits/stdc++.h>
using namespace std;
long long l,r,tl,tr;
void solve()
{
	cin>>l>>r;
	tl=max((long long)sqrtl(l)-3,1ll);
	tr=min((long long)sqrtl(r)+3,1000000000ll);
	while(tl*tl<l) tl++;
	while(tr*tr>r) tr--;
	cout<<max(tr-tl+1,0ll)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
