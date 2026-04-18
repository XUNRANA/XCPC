#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];

    int i=1,j=n;
    while(a[i]%2==0) i++;
    while(a[j]%2==0) j--;

    // cout<<i<<" "<<j<<"??\n";
    if(i>=j) cout<<"No\n";
    else
    {//i k l  j
        int k=i+1;
        int l=j-1;
        while(a[k]%2) k++;
        while(a[l]%2) l--;
        if(i<k&&k<l&&l<j) 
        {
            cout<<"Yes\n";
            cout<<i<<" "<<k<<" "<<l<<" "<<j<<"\n";
        }
        else cout<<"No\n";

    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}