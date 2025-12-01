#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{

    string s;
    cin>>s;
    int n=s.size();    
    vector<int>a;
    int cnt=1;
    for(int i=1;i<n;i++)
    if(s[i]==s[i-1]) cnt++;
    else
    {
        a.push_back(cnt);
        cnt=1;
    }
    a.push_back(cnt);

    if(a.size()==1) 
    {
        cout<<a[0]/2<<"\n";
        return ;
    }
    
    if(s[0]==s[n-1])
    {
        a[0]+=a.back();
        a.pop_back();
    }
    
    int ans=0;
    int f=0;
    for(auto i:a) 
    {
        if(i%2==0) f=1;
        ans+=i/2;
    }
    ans-=f;
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