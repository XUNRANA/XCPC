#include <bits/stdc++.h>
using namespace std;
int a[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int g=0;
    for(int i=2;i<=n;i++) g=__gcd(g,a[i]-a[i-1]);
    long long ans=0;
    for(int i=1;i<n;i++) ans+=(a[n]-a[i])/g;
    for(int i=n;i>=2;i--) 
    if(a[i]-a[i-1]!=g)
    {
        int x=a[i]-g;
        cout<<ans+(a[n]-x)/g<<"\n";
        return ;
    }
    cout<<ans+n<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
