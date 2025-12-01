#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int a[10000001];
int b[10000001];
void solve()
{
    a[0]=1;
    b[0]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x=a[i-1];
        int y=b[i-1];
        b[i]=(y*y%P+x*x%P)%P;
        a[i]=(x*x%P+2*x%P*y%P)%P;
    }
    cout<<a[n]<<" "<<b[n]<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}