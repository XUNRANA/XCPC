#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
int b[1000010];
int c[1000010];
void solve() 
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    set<array<int,2>>st;
    for(int i=1;i<=n;i++)
    {
        st.insert({a[i],i});
        if(i>=k)
        {
            while(i-(*st.begin())[1]>=k)
            {
                st.erase(st.begin());
            }
            while(i-(*st.rbegin())[1]>=k)
            {
                st.erase(--st.end());
            }
            b[i]=(*st.begin())[0];
            c[i]=(*st.rbegin())[0];
        }
    }
    for(int i=k;i<=n;i++) cout<<b[i]<<" \n"[i==n];
    for(int i=k;i<=n;i++) cout<<c[i]<<" \n"[i==n];
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