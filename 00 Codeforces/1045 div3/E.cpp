#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,c,d;
int a[200010];

void solve()
{
    cin>>n>>k>>c>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    //len [c,d]
    //at least k different int

    int ans=0;
    int l=1,l1=1;
    map<int,int>mp1,mp;
    for(int r=1;r<=n;r++)
    {
        mp[a[r]]++;
        mp1[a[r]]++;
        while(mp.size()>k)
        {
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        while(mp1.size()>=k)
        {
            mp1[a[l1]]--;
            if(mp1[a[l1]]==0) mp1.erase(a[l1]);
            l1++;
        }

        while(r-l+1>d) 
        {
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }

        while(r-l1+1>d)
        {
            mp1[a[l1]]--;
            if(mp1[a[l1]]==0) mp1.erase(a[l1]);
            l1++;
        }


                
        //[l,l1-1]
        if(mp.size()==k) 
        {
            ans+=max(min(l1-1,r-c+1)-l+1,0ll);

        }
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
}