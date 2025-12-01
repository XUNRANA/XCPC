#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=2*n+2;i++)
    {
        cin>>a[i];
    }
    string ans="a";
    for(int i=4;i<=2*n;i+=2)
    {
        if(a[i]==1)
        {
            ans+=char(((ans.back()-'a')^1)+'a');
        }
        else
        {
            ans+=ans.back();
        }
    }
    cout<<ans<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}