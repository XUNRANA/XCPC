#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
vector<int> no[200010];
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) no[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        no[x].push_back(y);
        no[y].push_back(x);
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(no[i].size()==2)
        {
            int mx1=no[no[i][0]].size()-1;
            int mx2=no[no[i][1]].size()-1;
            if(no[no[i][0]].size()==2) 
            {
                for(auto j:no[no[i][0]]) if(j!=i) mx1=max(mx1,(int)no[j].size());
            }
            if(no[no[i][1]].size()==2) 
            {
                for(auto j:no[no[i][1]]) if(j!=i) mx2=max(mx2,(int)no[j].size());
            }
            if(mx1+mx2==n-3) f=1;
                
        }
    }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}