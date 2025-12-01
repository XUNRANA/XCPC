#include <bits/stdc++.h>
using namespace std;





void solve()
{
    int n;
    char x;
    string s;
    cin>>n>>x>>s;
    cout<<x;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(islower(x)) x=toupper(x);
            else x=tolower(x);
        }
        else
        {
            if(islower(x)) 
            {
                if(x!='a') x--;
                else continue; 
            }
            else 
            {
                if(x!='Z') x++;
                else continue;
            }
        }
        cout<<x;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
