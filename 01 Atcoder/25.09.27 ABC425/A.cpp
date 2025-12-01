#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i&1) ans-=i*i*i;
        else ans+=i*i*i;
    }
    cout<<ans<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
