#include <bits/stdc++.h>
using namespace std;
#define int long long



vector<int>g[1000010];
int dep[1000010];
int mx[1000010];
int L[1000010];
int R[1000010];
int ans;
void dfs(int u,int fa)
{
    if(fa==-1) dep[u]=0;
    else dep[u]=dep[fa]+1;
    
    mx[u]=dep[u];
    vector<int>a;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        mx[u]=max(mx[u],mx[v]);
        a.push_back(mx[v]-dep[v]+1);
    }

    stack<int>st;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()) 
        {
            st.push(i);
            L[i]=-1;
        }
        else 
        {
            while(!st.empty()&&a[i]>=a[st.top()]) st.pop();

            if(st.empty())
            {
                L[i]=-1;
                st.push(i);
            }
            else
            {
                L[i]=st.top(); 
                st.push(i);
            }
        }
    }


    while(!st.empty()) st.pop();
    int n=a.size();
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty()) 
        {
            R[i]=n;
            st.push(i);
        }
        else 
        {
            while(!st.empty()&&a[i]>a[st.top()]) st.pop();
            if(st.empty())
            {
                R[i]=n;
                st.push(i);
            }
            else
            {
                R[i]=st.top();
                st.push(i);
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        int l=L[i]+1;
        int r=R[i]-1;
        res+=1ll*(i-l+1)*(r-i+1)*a[i];
    }
    ans+=res;

}
void solve()
{
    string s;
    cin>>s;
    stack<pair<char,int>>st;
    int id=0;
    for(auto i:s)
    {
        if(i=='(') 
        {
            id++;
            if(st.empty())
            {
                st.push({i,id});
                g[0].push_back(id);
            }
            else
            {
                int f=st.top().second;
                g[f].push_back(id);
                st.push({i,id});
            }
        }
        else
        {
            if(st.size()) st.pop();
        }
    }

    dfs(0,-1);
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}