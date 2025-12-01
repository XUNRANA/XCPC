#include <bits/stdc++.h>
using namespace std;





void solve()
{
    int n,m;
    set<string>st;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        st.insert(s);
    }
    cin>>m;
    set<string>st1;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        if(st.count(s)) st.erase(s);
        else st1.insert(s);
    }
    if(!st.size()) cout<<"All Back\n";
    else
    {
        cout<<"Missing: "<<st.size()<<"\n";
        for(auto i:st) cout<<i<<"\n";
    }

    if(!st1.size()) cout<<"All Known\n";
    else
    {
        cout<<"New: "<<st1.size()<<"\n";
        for(auto i:st1) cout<<i<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
