#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l[200010],r[200010],c[200010];
int p[400010];
void solve()
{
    cin>>n>>m;
    set<int>st;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i]>>c[i];
        st.insert(l[i]);
        st.insert(r[i]);
    }
    st.insert(1);
    st.insert(n);
    vector<int>a;
    for(auto i:st)
    {
        if(!a.empty()&&a.back()!=i-1) a.push_back(i-1);
        a.push_back(i);
    }
    for(int i=1;i<=a.size();i++) p[i]=0;
    for(int i=1;i<=m;i++)
    {
        int lf=lower_bound(a.begin(),a.end(),l[i])-a.begin()+1;
        int ri=lower_bound(a.begin(),a.end(),r[i])-a.begin()+1;
        p[lf]+=c[i];
        p[ri]-=c[i];
    }
    for(int i=1;i<=a.size();i++) p[i]+=p[i-1];
    int mx=1e18;
    for(int i=1;i<=a.size()-1;i++) mx=min(mx,p[i]);
    cout<<mx<<"\n";
    
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
