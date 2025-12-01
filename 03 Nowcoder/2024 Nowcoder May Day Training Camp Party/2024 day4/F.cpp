#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r,ans;
int is(int x)
{
	if(x%3==0) return 1;
	else 
	{
		if(x<10) return 0;
		else
		{	
			int y=x%10;
			x/=10;
			if(y%3==0) return 1;
			if(x%3==0) return 1;
			return 0;
		}
	}
}
void solve()
{
    cin>>l>>r;
    if(l>=100) cout<<r-l+1<<"\n";
    else 
    {
    	ans=0;
    	for(int i=l;i<=min(99ll,r);i++) if(is(i)) ans++;
    	ans+=max(0ll,r-100+1);
    	cout<<ans<<"\n";
	}
}

signed main()
{
    int T=1;
    cin>>T;
    while(T--) solve();
}
