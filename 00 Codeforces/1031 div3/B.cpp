#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    int n;
    cin>>n>>s; 
    if(n>=28)  cout<<"Yes\n";
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            if(s[i]==s[j]&&(i!=0||j!=n-1))
            {
                cout<<"Yes\n";
                return ;
            }
        }
        cout<<"No\n";
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