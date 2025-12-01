#include <bits/stdc++.h>
using namespace std;
#define int long long

int a,b,n,x[1010][1010],ans[1010][1010][2];
void print()
{
    for(int i=1;i<=a;i++,cout<<"\n")
    for(int j=1;j<=b;j++) cout<<ans[i][j][0]<<" ";

    cout<<"\n";

    for(int i=1;i<=a;i++,cout<<"\n")
    for(int j=1;j<=b;j++) cout<<ans[i][j][1]<<" ";
}
void solve()
{
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++) cin>>x[i][j];
    
    for(int i=1;i<=a;i++)
    {
        multiset<int>st;
        for(int j=1;j<=b;j++)
        {
            st.insert(x[i][j]);
            if(j>=n)
            {
                ans[i][j-n+1][0]=*st.begin();
                ans[i][j-n+1][1]=*st.rbegin();
                st.erase(st.find(x[i][j-n+1]));
            }
        }
    }
    
    // print();
    int res=1e18;
    for(int j=1;j<=b+1-n;j++)
    {
        multiset<int>st;
        for(int i=1;i<=a;i++)
        {
            st.insert(ans[i][j][0]);
            st.insert(ans[i][j][1]);
            if(i>=n)
            {
                res=min(res,(*st.rbegin())-(*st.begin()));
                st.erase(st.find(ans[i-n+1][j][0]));
                st.erase(st.find(ans[i-n+1][j][1]));
            }
        }
    }
    cout<<res<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
