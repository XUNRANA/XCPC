#include <bits/stdc++.h>
using namespace std;

int ans[100010];
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<n-1;i++) cout<<"&";
    if(count(s.begin(),s.end(),'1')==n) cout<<"^\n";
    else cout<<"&\n"; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}