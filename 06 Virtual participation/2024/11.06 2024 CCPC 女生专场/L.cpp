#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d;
void solve()
{
	int ans=0;
	cin>>a>>b>>c>>d;
	
	if(a>=4)
	{
		ans=4;
		
		int l=min(b,c);
		
		for(int i=0;i<=l;i++)
		{
			int c1=i;
			
			if(!c1) 
			{
				int k1=l-i;
				ans=max(ans,(c1+2)*(k1+2));
				continue;
			}
		
			int k1=min(l-i,d/c1);
	
			ans=max(ans,(c1+2)*(k1+2));
					
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
