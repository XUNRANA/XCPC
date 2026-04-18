#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
void solve()
{
    int n;
    cin>>n;
    set<int>st;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(y) b[x]=1;
        else a[x]=1;
        st.insert(x);
    }
    int f=0;
    for(auto i:st) if(a[i]&&!b[i]) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    if(!f) cout<<"NONE\n"; 

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}