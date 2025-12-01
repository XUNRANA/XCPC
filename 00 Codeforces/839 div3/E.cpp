#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[500010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s1=0,s2=0,s3=0;
    for(int i=1;i<=n;i++) 
    {
        s1+=(a[i]!=i);
        s2+=(a[i]!=(n+1-i));
        s3+=((a[i]!=i)&(a[i]!=(n+1-i)));
    }
    // cout<<s1<<" "<<s2<<" "<<s3<<"??\n";
    if(s3+s1<=s2) cout<<"First\n";
    else if(s3+s2<s1) cout<<"Second\n";
    else cout<<"Tie\n";
    // 3 4 5 2 1
    // 1 2 3 4 5
    // 5 4 3 2 1
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}