#include <bits/stdc++.h>
using namespace std;
int n,t,a[1010];
void solve()
{
    cin>>n>>t;
    stack< array<int,2> >st;
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int>ans;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=t) ans.push_back(i); 
        else 
        {
            s+=a[i];
            st.push({a[i],i});
        }
    }
    while(!st.empty())
    {
        t=s/st.size();
        s=0;
        stack< array<int,2> >nst;
        while(!st.empty())
        {
            int val=st.top()[0];
            int idx=st.top()[1];
            st.pop();
            if(val<=t) ans.push_back(idx);
            else 
            {
                s+=val;
                nst.push({val,idx});
            }
        }
        st=nst;
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}