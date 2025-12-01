#include <bits/stdc++.h>
using namespace std;


int is(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
int a[11];
void solve()
{
    int l,r,n;
    cin>>l>>r>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=l;i<=r;i++) 
    {
        int f=0;
        for(int j=1;j<=n;j++) if(i%a[j]==0) f=1;
        if(!f&&!is(i)) ans++;
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
