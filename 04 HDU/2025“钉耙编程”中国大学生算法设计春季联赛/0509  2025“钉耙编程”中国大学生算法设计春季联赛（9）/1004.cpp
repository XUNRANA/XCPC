#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve() 
{
    int v,w;
    cin>>v>>w;
    // v=rng()%100;
    // w=4;
    // w=rng()%100;
    // cout<<v<<" "<<w<<":";
    
    if(v<=w) cout<<"1\n";
    else if(w==1) cout<<v<<"\n";
    else if(w==2) cout<<(v+1)/w<<"\n";
    else
    {
        if(w&1) 
        {
            w=(w+1)/2;
            cout<<v/w<<"\n";
        }
        else
        {
            int ans=(v+w-1)/w;
            ans=max(ans,(v+1)/(w/2+1));
            cout<<ans<<"\n";
        }
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