#include <bits/stdc++.h>
using namespace std;
#define int long long

string fxs(int x)
{
    string ans="";
    int f1=x/60;
    int f2=x%60;
    if(f1<10) ans+='0';
    ans+=to_string(f1);
    if(f2<10) ans+='0';
    ans+=to_string(f2);
    return ans;
}
int fx(int x,int y)
{
    int ans=0;
    for(int i=x+1;i<=y;i++)
    {
        string s1=fxs(i-1);
        string s2=fxs(i);
        for(int j=0;j<4;j++)
        ans+=(s1[j]!=s2[j]);
        // cout<<s1<<" "<<s2<<"\n";
    }
    return ans;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int a1=stoi(s1.substr(0,2))*60+stoi(s1.substr(3,2));
    int a2=stoi(s2.substr(0,2))*60+stoi(s2.substr(3,2));
    if(a1<=a2)
    {
        cout<<fx(a1,a2)<<"\n";
        
    }
    else
    {
        int a3=24*60-1;
        int a4=0;
        cout<<fx(a1,a3)+fx(a4,a2)+4<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}