#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
void solve()
{
    cin>>n;
    int mx=0;
    set<int>st;
    map<int,int>mp;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        if(mp.count(a[i])) continue;
        mp[a[i]]=i;
        st.insert(a[i]);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    if(mx==a[i]) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    cout<<"\n";

    int m;
    cin>>m;
    while(m--)
    {
        int x;
        cin>>x;
        if(x>=mx) cout<<"0\n";
        else 
        {
            auto it=st.upper_bound(x);
            cout<<mp[*it]<<"\n";
        }
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}