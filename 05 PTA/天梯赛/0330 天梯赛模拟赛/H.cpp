#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> fx(string s)
{
    int num=0;
    int a1=0,a2=0;// a1x+a2;
    int f=1;
    for(auto i:s)
    {
        if(i=='-')
        {
            if(num) a2+=num*f;
            num=0;
            f=-1;
        }
        else if(i=='+') 
        {
            if(num) a2+=num*f;
            num=0;
            f=1;
        }
        else if(i=='x')
        {
            if(num==0) a1+=1*f;
            else a1+=num*f;
            f=1;
            num=0;
        }
        else if(isdigit(i))
        {
            num=num*10+(i-'0');
        }
    }
    if(num) a2+=num*f;
    return {a1,a2};
}
void solve() 
{
    string s,a,b;
    cin>>s;
    int f=0;
    for(auto i:s)
    {
        if(i=='=') 
        {
            f=1;
            continue;
        }
        if(f) a+=i;
        else b+=i;
    }
    int a1,a2,a3,a4;
    a1=fx(a).first;
    a2=fx(a).second;
    a3=fx(b).first;
    a4=fx(b).second;
    printf("x = %.2f",1.0*(a4-a2)/(a1-a3));
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}