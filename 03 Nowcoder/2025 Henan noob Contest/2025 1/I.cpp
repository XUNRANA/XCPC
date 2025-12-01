#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,l,r;
    string s;
    cin>>n>>s;
    cin>>l>>r;
    l--;
    r--;
    int c0=0,c1=0;

    for(int i=0;i<l-1;i++) 
    if(s.substr(i,2)=="10") c1++;
    else if(s.substr(i,2)=="01") c0++;

    for(int i=r+1;i<n-1;i++)
    if(s.substr(i,2)=="10") c1++;
    else if(s.substr(i,2)=="01") c0++;

    if(l!=0&&r!=n-1) 
    {
        if(s[l-1]==s[r+1])
        {
            if(c0==c1) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else
        {
            if(s[l-1]=='0') c0++;
            else c1++;


            if(c0==c1) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    else
    {
        if(c0==c1) cout<<"Yes\n";
        else 
        {
            if(l==0)
            {
                if(s[r+1]=='1') c0++;
                else c1++; 
            }
            else
            {
                if(s[l-1]=='0') c0++;
                else c1++;
            }
            
            if(c0==c1) cout<<"Yes\n";
            else cout<<"No\n";
        }
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