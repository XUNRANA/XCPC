#include <bits/stdc++.h>
using namespace std;
int n;


void solve()
{
    cin>>n;
    vector<int>a2,a3,a6,b;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        if(x%6==0) a6.push_back(x);
        else if(x%2==0) a2.push_back(x);
        else if(x%3==0) a3.push_back(x);
        else b.push_back(x);
    }
    vector<int>ans;
    for(auto i:a6) ans.push_back(i);
    for(auto i:a2) ans.push_back(i);
    for(auto i:b) ans.push_back(i);
    for(auto i:a3) ans.push_back(i);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}