#include <bits/stdc++.h>
using namespace std;
int a[1010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int c1=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==a[i]) c1++;
    }
    if(c1==n) cout<<"The Fool of Tarot ak!\n";
    else if(c1==0) cout<<"The Fool of Tarot over!\n";
    else if(c1>=n/2) cout<<"The Fool of Tarot Okay!\n";
    else cout<<"The Fool of Tarot so-so!\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}