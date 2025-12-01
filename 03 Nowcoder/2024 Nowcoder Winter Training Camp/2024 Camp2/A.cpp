#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,x,y,z; 
void solve()
{
	ans=0;
    cin>>x>>y>>z;
    if(x==150) ans++;
    else if(x==200) ans+=2;
    if(y==45) ans+=2;
    else if(y==34||y==36||y==38||y==40) ans++;
    if(z==45) ans+=2;
    else if(z==34||z==36||z==38||z==40) ans++;
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
