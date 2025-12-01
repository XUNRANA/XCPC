#include <bits/stdc++.h>
using namespace std;
int a[10000010];

void solve()
{
    int n;
    cin>>n;
    vector<int>c;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]!=1) c.push_back(0);
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            c.push_back(cnt);
            cnt=1;
        }
    }
    c.push_back(cnt);



    int ans=0;
    for(int i=0;i<c.size();i+=2)
    {
        int res=0;
        for(int j=i;j<=i+3;j++)
        if(j<c.size()) res+=c[j];

        ans=max(ans,res);
    } 
    cout<<ans<<"\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}