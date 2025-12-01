#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e4+5; 
int c[MAXN],n,ans; 
bitset<MAXN>bs[MAXN]; 
int main() 
{
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>c[i]; 
    for(int i=n;i>=1;i--) 
    {
        bs[i][c[i]]=1;
        if(i+c[i]<=n) bs[i]|=bs[i+c[i]];
        if(i*2<=n) bs[i]|=bs[i*2]; 
        ans=max(ans,(int)bs[i].count()); 
    }
    cout<<ans<<"\n";
}