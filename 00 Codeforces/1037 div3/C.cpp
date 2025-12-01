#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=a[k];
    sort(a+1,a+1+n);
    int s=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==x&&i!=n)
        {
            s+=a[i+1]-a[i];
            if(s-1>a[i])
            {
                cout<<"NO\n";
                return ;
            }   
            x=a[i+1];
        }
    }
    cout<<"YES\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
