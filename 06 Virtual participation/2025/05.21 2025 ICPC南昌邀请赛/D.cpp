#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    map<int,int>mp1,mp2,mp3;
    for(int i=1;i<=n;i++) 
    {
        int x1,x2,y11,y2,z1,z2;
        cin>>x1>>y11>>z1>>x2>>y2>>z2;
        
        if(x1>x2) swap(x1,x2);
        if(y11>y2) swap(y11,y2);
        if(z1>z2) swap(z1,z2);

        mp1[x1]++;
        mp1[x2+1]--;
        mp2[y11]++;
        mp2[y2+1]--;
        mp3[z1]++;
        mp3[z2+1]--;
    }

    int ans=1;
    int p=0;
    for(auto &i:mp1)
    {
        i.second+=p;
        ans=max(ans,i.second);
        p=i.second;
    }
    p=0;
    for(auto &i:mp2)
    {
        i.second+=p;
        ans=max(ans,i.second);
        p=i.second;
    }
    
    p=0;
    for(auto &i:mp3)
    {
        i.second+=p;
        ans=max(ans,i.second);
        p=i.second;
    }
    cout<<ans<<"\n";
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
