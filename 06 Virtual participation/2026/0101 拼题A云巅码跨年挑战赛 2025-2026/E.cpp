#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string a,b;
    cin>>a>>b;



    string c=a.substr(2);
    string d=b.substr(2);
    while(c[0]=='0') c=c.substr(1);
    while(d[0]=='0') d=d.substr(1);

    if(c.size()>d.size()) cout<<a<<" ";
    else if(c.size()<d.size()) cout<<b<<" ";
    else
    {
        int f=0;
        for(int i=0;i<c.size();i++)
        if(c[i]>d[i]) 
        {
            f=1;
            break;
        }
        else if(c[i]<d[i])
        {
            f=2;
            break;
        }
        if(f==1) cout<<a<<" ";
        else if(f==2) cout<<b<<" ";
    }


    string a1=a;
    string b1=b;
    while(a1.size()<b1.size()) a1+='0';
    while(a1.size()>b1.size()) b1+='0';
    for(int i=0;i<a1.size();i++) 
    if(a1[i]>b1[i])
    {
        cout<<a<<"\n";
        return ;
    }
    else if(a1[i]<b1[i])
    {
        cout<<b<<"\n";
        return ;
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