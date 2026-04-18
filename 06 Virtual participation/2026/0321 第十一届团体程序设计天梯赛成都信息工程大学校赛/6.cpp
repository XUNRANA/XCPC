#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;
int is(int y)
{
    if(y%4==0&&y%100!=0) return 1;
    if(y%400==0) return 1; 
    return 0;
}
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void init()
{
    int c=0;
    for(int y=1000;y<=1367;y++)
    {
        for(int m=1;m<=12;m++)
        {
            for(int d=1;d<=mon[m];d++)
            {
                string s="";
                s+=to_string(y);
                s+="-";
                if(m<10) s+="0";
                s+=to_string(m);
                s+="-";
                if(d<10) s+="0";
                s+=to_string(d);
                mp[s]=c++;
            }
            if(m==2&&is(y))
            {
                string s="";
                s+=to_string(y);
                s+="-02-29";
                mp[s]=c++;
            }
        }
    }
}
void solve()
{
    string s;
    cin>>s;
    string p="1349-06-28";
    int x=mp[s]-mp[p];
    if(x>0) cout<<"hai cha "+to_string(x)+" day!\n";
    else if(x<0) cout<<"guo qv le "+to_string(-x)+" day?\n";
    else cout<<"jiu shi today.\n";
}
int main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}