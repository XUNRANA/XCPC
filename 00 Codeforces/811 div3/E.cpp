#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve() 
{
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]%10==0||a[i]%10==5) f=1;
    }
    if(f)
    {    
        for(int i=1;i<=n;i++) a[i]+=a[i]%10;
        sort(a+1,a+1+n);
        if(a[1]==a[n]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    else
    {
        sort(a+1,a+1+n);
        if(a[1]==a[n]) 
        {
            cout<<"Yes\n";
            return ;
        }
        vector<int>cnt(20,0);
        for(int i=1;i<=n;i++) 
        {
            if(a[i]&1) a[i]+=a[i]%10;
            cnt[a[i]%20]=1;
        }
        
        priority_queue<int,vector<int>,greater<int>>q;
        int mx=0;
        for(int i=1;i<20;i++) 
        if(cnt[i]) 
        {
            q.push(i);
            mx=max(mx,i);
        }
        int c=1000;
        while(!q.empty()&&c--)
        {
            auto u=q.top();
            q.pop();
            if(u==mx)
            {
                cout<<"Yes\n";
                return ;
            }
            else
            {
                u+=u%10;
                mx=max(mx,u);
                q.push(u);
            }
        }
        cout<<"No\n";
    }
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