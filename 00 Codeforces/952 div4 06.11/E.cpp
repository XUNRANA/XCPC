#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int x,y,z,K,ans=0;
	cin>>x>>y>>z>>K;
	if(x>y) swap(x,y);
	if(y>z) swap(y,z);
	if(x>y) swap(x,y);
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(K%(i*j)==0&&K/(i*j)<=z)
			ans=max(ans,(x-i+1)*(y-j+1)*(z-K/(i*j)+1));
		}
	}
	
	
	cout<<ans<<"\n";

}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
