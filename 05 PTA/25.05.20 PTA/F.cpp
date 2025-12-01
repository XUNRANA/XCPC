#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        for(auto &i:a) if(isupper(i)) i=tolower(i);
        for(auto &i:b) if(isupper(i)) i=tolower(i);
        if(a.size()==b.size())
        {
            int c1=0;
            int f1=0,f2=0;
            set<pair<int,int>>st;
            set<char>sa,sb;
            for(int i=0;i<a.size();i++)
            if(a[i]==b[i]) c1++;
            else 
            {
                if(sa.count(b[i])||sb.count(a[i])) f1=1;
                if(st.count({b[i],a[i]}))
                {
                    f2=2;
                }
                sa.insert(a[i]);
                sb.insert(b[i]);
                st.insert({a[i],b[i]});
            }
            if(f2) c1+=2;
            else if(f1) c1+=1;
            if(c1>=4) cout<<"how pay\n";
            else cout<<"bull pay\n";
        }
        else cout<<"bull pay\n";
    }
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