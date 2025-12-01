#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1010][1010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        stack<int>st;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0) continue;
            if(a[i][j]<0) 
            {
                while(!st.empty())
                {
                    int k=st.top();
                    st.pop();
                    if(a[i][k]+a[i][j]>=0)
                    {
                        a[i][k]+=a[i][j];
                        a[i][j]=0;
                        if(a[i][k]) st.push(k);
                        break;
                    }
                    else 
                    {
                        a[i][j]+=a[i][k];
                        a[i][k]=0;
                    }
                }
                ans+=-a[i][j];
                a[i][j]=0;
            }
            else st.push(j);
        }
        while(!st.empty()) 
        {
            int k=st.top();
            st.pop();
            if(i==n) ans+=a[i][k];
            else a[i+1][k]+=a[i][k];
        }
    }
    cout<<ans<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}