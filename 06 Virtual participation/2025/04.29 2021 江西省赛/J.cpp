#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100010];
bool ck(int x)
{
    map<int,int>mp;
    set<pair<int,int>>st;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(mp.count(a[i]))
        {
            cnt++;
            if(cnt>=k) return 1;
            st.erase({mp[a[i]],a[i]});
            mp[a[i]]=i;
            st.insert({mp[a[i]],a[i]});
        }
        else 
        {
            if(mp.size()==x)
            {
                mp.erase(st.begin()->second);
                st.erase(st.begin());
            }
            mp[a[i]]=i;
            st.insert({mp[a[i]],a[i]});
        }
    }
    return 0;
}
void solve() 
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(!ck(n))
    {
        cout<<"cbddl\n";
        return ;
    }
    int l=1,r=n;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
} 

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
