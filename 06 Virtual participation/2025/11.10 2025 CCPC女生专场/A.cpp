#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,s,t;
    cin>>n>>s>>t;
    if(t>=s)
    {
        int d=t-s;
        if(2*d<n) cout<<"1\n";
        else cout<<"2\n";
    }
    else
    {
        int d=s-t;
        if(2*d<n) cout<<"2\n";
        else cout<<"1\n";
    }
}
int main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  int T=1;
  // cin>>T;
  while(T--) solve();
}