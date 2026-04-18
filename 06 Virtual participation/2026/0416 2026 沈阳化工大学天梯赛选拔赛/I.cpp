#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];
void solve()
{
    cin>>n>>k;
    queue<int>q;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        q.push(x);
    }

    int a=0;
    int b=0;
    int mx=0;
    int mi=1e9+1;
    while(k--)
    {
        if(!a) 
        {
            a=q.front();
            q.pop();
        }
        if(!b)
        {
            b=q.front();
            q.pop();
        }

        if(!k) 
        {
            cout<<min(a,b)<<" "<<max(a,b)<<"\n";
            break;
        }

        if(max(a,b)==mx)
        {
            q.push(min(a,b));
            q.push(max(a,b));
            a=b=mx=0;
            mi=1e9+1;
            continue;
        }
        



        mx=max(a,b);
        mi=min(a,b);
        if(a==mi) a=0;
        else b=0;
        q.push(mi); 
    }
    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

