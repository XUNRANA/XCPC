#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int>a,b;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') b.push_back(i+2);//是割点
        else a.push_back(i+2);//不是割点        
    }

    vector<array<int,2>>ans;
    if(a.size()>=2) 
    {
        int l=1;
        for(auto i:a)
        {
            ans.push_back({l,i});
            l=i;
        }
        ans.push_back({l,1});

        l=1;
        for(auto i:b)
        {
            ans.push_back({l,i});
            l=i;
        }
        ans.push_back({l,n});
        cout<<ans.size()<<"\n";
        for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
    }
    else
    {
        if(a.size()==1&&a[0]==n-1)
        {
            ans.push_back({n,1});
            for(int i=1;i<n-1;i++) ans.push_back({i,i+1});
            cout<<ans.size()<<"\n";
            for(auto i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
        }
        else cout<<"-1\n";
    }

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}