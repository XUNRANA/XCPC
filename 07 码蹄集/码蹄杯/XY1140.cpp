#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,x;
int a[100010];
int ans[100010];

void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]=i;
    }

    stack<int>st;
 
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        if(st.empty()) st.push(x);
        else 
        {
            while(!st.empty()&&st.top()>x) st.pop();
            st.push(x);
        }
        ans[i]=st.size();
    }

    while(!st.empty()) st.pop();

    for(int i=n;i>=1;i--)
    {
        int x=a[i];
        if(st.empty()) st.push(x);
        else 
        {
            while(!st.empty()&&st.top()>x) st.pop();
            st.push(x);
        }
        ans[i]+=st.size();
    }

    int res=0;
    for(int i=1;i<=n;i++) res=max(res,ans[i]-1);
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

