#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    int now=1;
    int x;
    while(cin>>x)
    {
        if(x==a+b)
        {
            cout << x << " Accepted " 
     << setfill('0') << setw(2) << now / 3600 << ":"
     << setw(2) << now % 3600 / 60 << ":"
     << setw(2) << now % 60 << "\n";
            // cout<<x<<" "<<"Accepted"<<" "<<now/3600<<":"<<now%3600/60<<":"<<now%3600%60<<"\n";
            return ;
        }
        
        if(now+2>60*60*3)
        {
            cout << x << " Wrong Answer " 
     << setfill('0') << setw(2) << now / 3600 << ":"
     << setw(2) << now % 3600 / 60 << ":"
     << setw(2) << now % 60 << "\n";
            // cout<<x<<" "<<"Wrong Answer"<<" "<<now/3600<<":"<<now%3600/60<<":"<<now%3600%60<<"\n";
            return ;
        }
        now+=2;
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