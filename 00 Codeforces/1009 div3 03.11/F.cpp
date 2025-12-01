#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	int res=0;
	for(int i=1;i<30;i++)
	{
		int s=1<<i;
		int rr1=r1/s*s;
		int rr2=r2/s*s;
		int ll1=(l1+s-1)/s*s;
		int ll2=(l2+s-1)/s*s;
		if(ll2>=rr2||ll1>=rr1) continue;
		res-=3ll*(rr1-ll1)/s*(rr2-ll2)/s; 
	}
	res+=(r1-l1)*(r2-l2);
	cout<<res<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

