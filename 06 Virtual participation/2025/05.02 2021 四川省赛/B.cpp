#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int>g[100010];
int a[100010];
int ans[100010];
void solve () 
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++) g[i].clear();
    for(int i=0;i<n;i++) ans[i]=0;
    
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        a[i]=x;
        g[x].push_back(i);
    }
    int r=m/n;
    if(r&1) r--;
    int t=m-r*n;//剩下的
    for(int i=1;i<=k;i++)
    if(g[i].size())
    {
        if(g[i].size()&1)
        {
            for(auto j:g[i])
            {
                ans[j]+=r/2;
            }
        }
        else
        {
            int c=0;
            for(auto j:g[i])
            {
                c++;
                if(c%2==0) ans[j]+=r;
            }
        }
    }
    set<int>st;
    for(int i=0;i<t;i++)
    {
        int j=i%n;
        if(st.count(a[j])) 
        {
            ans[j]+=1;
            st.erase(a[j]);
        }
        else st.insert(a[j]);
    }
    int f=0;
    for(int i=0;i<n;i++) 
    {
        if(f) cout<<" ";
        cout<<ans[i];
        f=1;
    }
    cout<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
     cin >> t;
    while (t--)
    solve();
    return 0;
}