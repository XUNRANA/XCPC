#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(i+1<n&&s[i]>s[i+1])
        {
            while(i+1<n&&s[i]>=s[i+1])
            {
                swap(s[i],s[i+1]);
                i++;
            }
            break;
        }
    }
    cout<<s<<"\n";
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