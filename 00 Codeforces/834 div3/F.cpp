#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
void solve()
{
    int n,p;
    cin>>n>>p;
    set<int>st;
    for(int i=n;i>=1;i--)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    if(st.size()==p)
    {
        cout<<"0\n";
        return ;
    }
    int l=0,r=p-1;
    while(st.count(l)) l++;
    while(st.count(r)) r--;

    if(l>a[1]) cout<<r-a[1]<<"\n";
    else//l r a[1] r
    {
        int res=p-a[1];
        st.insert(0);
        a[n+1]=0;
        for(int i=2;i<=n+1;i++)
        {
            a[i]+=1;
            if(a[i]<p) 
            {
                st.insert(a[i]);
                break;
            }
        }
        r=min(r,a[1]);
        while(st.count(r)) r--;
        res+=max(r,0ll);
        cout<<res<<"\n";
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


