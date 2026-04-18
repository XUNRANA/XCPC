#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    int x=b-a;
    cout<<x<<"\n";
    if(x>250) cout<<"jiu ting tu ran de...\n";
    else if(x<=0) cout<<"hai sheng ma?\n";
    else cout<<"nin tai cong ming le!\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}