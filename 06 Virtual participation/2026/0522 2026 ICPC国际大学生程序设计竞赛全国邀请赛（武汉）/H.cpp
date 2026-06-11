#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    set<int>a,b;
    multiset<int>va,vb;
    
    a.insert(0);
    a.insert(n);
    b.insert(0);
    b.insert(m);
    va.insert(n);
    vb.insert(m);
    while(q--)
    {
        int op,k;
        cin>>op>>k;
        // cout<<op<<" "<<k<<"???\n";   
        if(op==1)
        {
            auto it=a.upper_bound(k);
            int r=*it;
            it--;
            int l=*it;
            va.erase(va.find(r-l));
            va.insert(r-k);
            va.insert(k-l);
            a.insert(k);
            cout<<(*va.rbegin())*(*vb.rbegin())<<"\n";
        }
        else
        {
            auto it=b.upper_bound(k);
            int r=*it;
            it--;
            int l=*it;
            vb.erase(vb.find(r-l));
            vb.insert(r-k);
            vb.insert(k-l);
            b.insert(k);
            cout<<(*va.rbegin())*(*vb.rbegin())<<"\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}