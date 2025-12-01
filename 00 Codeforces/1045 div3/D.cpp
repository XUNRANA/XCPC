#include <bits/stdc++.h>
using namespace std;
#define int long long


// baabaabaa


// aaabaabaaab

// bbbaaa 6 
// abbbaa 3
// aabbba 2
// aaabbb 3



void solve()
{
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;

    vector<int>pa(n+1,0),pb(n+1,0);
    for(int i=1;i<=n;i++)       
    if(s[i]=='a') 
    {
        pa[i]=pa[i-1]+1;
        pb[i]=pb[i-1];
    }
    else 
    {
        pa[i]=pa[i-1];
        pb[i]=pb[i-1]+1;
    }
    
    int fa=0,la=n+1,fb=0,lb=n+1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='a')
        {
            if(!fa) fa=la=i;
            else la=i;
        }
        else
        {
            if(!fb) fb=lb=i;
            else lb=i;
        }
    }


    // cout<<fa<<" "<<la<<"?\n";
    // cout<<fb<<" "<<lb<<"?\n";


    if(!fa||!fb)
    {
        cout<<"0\n";
        return ;
    }

    int sa=0,sb=0;
    for(int i=fa;i<=la;i++)
    {
        if(s[i]=='b')
        sa+=min(pa[i]-pa[fa-1],pa[la]-pa[i]);
    }

    for(int i=fb;i<=lb;i++)
    {
        if(s[i]=='a')
        sb+=min(pb[i]-pb[fb-1],pb[lb]-pb[i]);
    }
    cout<<min(sa,sb)<<"\n";
    // cout<<sa<<" "<<sb<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}