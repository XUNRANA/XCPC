#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110][1010];
int mx[110][1010];
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int mx1=0,mx2=0;
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
            if(a[i][j]>=mx1)
            {
                mx2=mx1;
                mx1=a[i][j];
            }
            else if(a[i][j]>mx2)
            {
                mx2=a[i][j];
            }
        }

        for(int j=1;j<=m;j++) 
        if(a[i][j]==mx1) mx[i][j]=mx2;
        else mx[i][j]=mx1;
    }
    int ans=0;
    for(int j=1;j<=m;j++)
    {
        int res=0;
        for(int i=1;i<=n;i++) res+=a[i][j];
        priority_queue<int>q;
        for(int i=1;i<=n;i++) q.push(mx[i][j]-a[i][j]);
        // 4:1
        // 5:2
        // 6:2
        int c=(n-1)/2;
        while(c--)
        {
            if(!q.empty()&&q.top()>0) res+=q.top();
            else break;
            q.pop();
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
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