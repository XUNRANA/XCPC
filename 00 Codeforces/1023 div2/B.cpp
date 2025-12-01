#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve () 
{
    int n,k;
    cin>>n>>k;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a+1,a+1+n);
    if(max(a[n]-1,a[n-1])-a[1]>k) cout<<"Jerry\n";
    else 
    {
        if(s&1) cout<<"Tom\n";
        else cout<<"Jerry\n";
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}