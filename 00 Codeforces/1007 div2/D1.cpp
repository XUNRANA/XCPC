#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[400010];
int p[400010];
int n,l,r;
int fx(int x)
{
    if(x<=2*n) return a[x];
    x/=2;
    if(x%2==0) return p[n]^fx(x);
    else return p[n];
}

void solve()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=a[i]^p[i-1];
    if(n%2==0)//n变成奇数
    {
        n++;
        a[n]=p[n/2];
        p[n]=p[n-1]^a[n];
    }
    for(int i=n+1;i<=2*n;i++) a[i]=p[i/2];
    for(int i=n+1;i<=2*n;i++) p[i]=a[i]^p[i-1]; 
    //n为奇数
    if(l<=2*n) cout<<a[l]<<"\n";
    else cout<<fx(l)<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

