#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[2][50];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[1][i];
    for(int i=1;i<=n;i++) cin>>a[2][i];

    vector<array<int,2>>ans;
    while(1)
    {
        int f=0;
        for(int i=1;i<=n-1;i++)
        {
            if(a[1][i]>a[1][i+1]) 
            {
                f=1;
                swap(a[1][i],a[1][i+1]);
                ans.push_back({1,i});
            }

            if(a[2][i]>a[2][i+1]) 
            {
                f=1;
                swap(a[2][i],a[2][i+1]);
                ans.push_back({2,i});
            }
        }
        if(!f) break;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[1][i]>a[2][i]) 
        {
            swap(a[1][i],a[2][i]);
            ans.push_back({3,i});
        }
    }

    // 1 2 3 4 5 6
    // 7 8 9 10 11 12

    // 1 2 3 10 11 12
    // 7 8 9 4 5 6
    
    // for(int i=1;i<=n;i++) cout<<a[1][i]<<" \n"[i==n];
    // for(int i=1;i<=n;i++) cout<<a[2][i]<<" \n"[i==n];

    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}