#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[40010];
int b[40010];
int vt[40010];
int fx(int i)
{
    queue<int>q;
    q.push(i);
    int j=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        if(vt[u]) continue;
        vt[u]=1;
        b[++j]=u;
        
        if(u+u<=n) q.push(u+u);
        if(u+a[u]<=n) q.push(u+a[u]);
    }
    set<int>st;
    for(int i=1;i<=j;i++) 
    {
        vt[b[i]]=0;
        st.insert(a[b[i]]);
    }
    return st.size();
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,fx(i));
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}