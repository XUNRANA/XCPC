#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,h[9];
void solve()
{
	cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(a==0)
        {
            h[b]=max(h[b],h[b+1])+3;
            h[b+1]=h[b]-2;
        }
        else if(a==90) h[b]=h[b+1]=h[b+2]=max({h[b]+2,h[b+1]+1,h[b+2]+1});
        else if(a==180) h[b]=h[b+1]=max(h[b]+1,h[b+1]+3);
        else if(a==270) h[b]=h[b+1]=max({h[b],h[b+1],h[b+2]})+1,h[b+2]=h[b]+1;
    }
    for(int i=1;i<=8;i++) cout<<h[i]<<" ";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
