#include <bits/stdc++.h>
using namespace std;
int is[200010];
int a[200010];
int n;
void solve() 
{
    cin>>n;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]) a[j++]=a[i];
    }
    n=j-1;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        is[i]=0;
        mp[x].push_back(i);
    }
    is[0]=is[n+1]=0;
    stack<int>st;
    for(auto i:mp) st.push(i.first);
    int ans=0;
    while(!st.empty()) 
    {
        int x=st.top();
        st.pop();
        for(auto i:mp[x])
        {
            is[i]|=is[i-1];
            is[i]|=is[i+1];
            if(!is[i])
            {
                ans++;
                is[i]=1;
            }
        }
    }
    cout<<ans<<"\n";
}



signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}