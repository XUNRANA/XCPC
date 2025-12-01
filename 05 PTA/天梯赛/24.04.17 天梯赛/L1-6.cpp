#include <bits/stdc++.h>
using namespace std;
/*
AcrosstheGreatWall,wecanreacheverycornerintheworld
5
10 18 ery cor
32 40 , we
1 6 tW all
14 18 rnerr eache
1 1 e r

*/
int main()
{
    string s;
    getline(cin,s);
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        string c,d,t;
        cin>>a>>b>>c>>d;
        t=s.substr(a-1,b-a+1);
       // cout<<t<<"\n";
        s.erase(a-1,b-a+1);
       // cout<<s<<"\n";
        auto it=s.find(c+d);
        if(it==-1) s+=t;
        else s=s.substr(0,it)+c+t+d+s.substr(it+c.size()+d.size());
       // cout<<it<<"\n";
    } 
    cout<<s<<"\n";
}
