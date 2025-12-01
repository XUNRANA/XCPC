#include <bits/stdc++.h>
using namespace std;
#define int long long

int a,b,c1,c2,c3;
int d[1010];
int vt[1010];
void solve()
{
    cin>>a>>b>>c1>>c2>>c3;
    if(b<a) cout<<(a-b)*c2<<"\n";
    else 
    {
        
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
        for(int i=a;i>=1;i--) d[i]=(a-i)*c2;
        for(int i=a+1;i<=b;i++) d[i]=(i-a)*c1;

        for(int i=1;i<=b;i++) 
        {
            q.push({d[i],i});
            vt[i]=0;
        }
        
        int ans=d[b];
        while(!q.empty())
        {
            int w=q.top()[0];
            int u=q.top()[1];
            q.pop();
            if(vt[u]) continue;
            vt[u]=1;

            if(w>ans) break;
            
            if(2*u<=b&&d[2*u]>w+c3)
            {
                d[2*u]=w+c3;
                q.push({d[2*u],2*u});
            }
            
            if(u-1>=1&&d[u-1]>w+c2)
            {
                d[u-1]=w+c2;
                q.push({d[u-1],u-1});
            }

            if(u+1<=b&&d[u+1]>w+c1)
            {
                d[u+1]=w+c1;
                q.push({d[u+1],u+1});
            }
            
            if(2*u>b) ans=min(ans,w+c3+(2*u-b)*c2);
        }


        // for(int i=1;i<=b;i++) cout<<d[i]<<" ";
        // cout<<"\n";
        ans=min(ans,d[b]);
        cout<<ans<<"\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}