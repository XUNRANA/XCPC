#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int l[N],r[N],x[N],s[N],ans,n,q,ml,mr,mx;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>l[i]>>r[i]>>x[i];
        s[l[i]]+=x[i];
		s[r[i]+1]-=x[i];
    }
    for(int i=1;i<=n;i++) s[i]+=s[i-1],ans=max(ans,s[i]);
    for(int i=1;i<=n;i++)
    {
        if(s[i]==ans)
        {
        	if(!ml) ml=mr=i;
        	else mr=i;
        }
    }
    for(int i=1;i<=q;i++) if(l[i]<=ml&&r[i]>=mr) mx=max(mx,x[i]);
    cout<<ans-mx;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
