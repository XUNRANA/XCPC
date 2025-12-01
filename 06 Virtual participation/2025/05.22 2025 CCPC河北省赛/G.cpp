#include <bits/stdc++.h>
using namespace std;
#define int long long

void fx(int x1,int y1,int x,string s)
{
    for(auto i:s)
    if(i=='D') x++,x1++;
    else if(i=='A') x--,x1--;
    else if(i=='S') x/=2,y1--;
    else x*=2,y1++;
    cout<<x1<<" "<<y1<<" "<<x<<"\n";
}
void solve()
{
    int x1,y1,x2,y2,x,y;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    // fx(x1,y1,x,"ASSWDWWD");
    string s="";
    while(y)
    {
        if(y&1) 
        {
            s+='D';
            x2--;
            y--;
        }
        s+='W';
        y2--;
        y/=2;
    }
    reverse(s.begin(),s.end());
    
    string ans="";

    while(x!=0)
    {
        ans+='S';
        x/=2;
        y1--;
    }
    
    while(x1>x2) 
    {
        x1--;
        ans+='A';
        x--;
    }
    while(x1<x2)
    {
        x1++;
        ans+='D';
        x++;
    }

    

    while(x!=0)
    {
        ans+='S';
        x/=2;
        y1--;
    }

    while(y1>y2)
    {
        y1--;
        ans+='S';
    }
    
    while(y1<y2)
    {
        y1++;
        ans+='W';
    }
    
    cout<<ans+s<<"\n";
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
