#include <bits/stdc++.h>
using namespace std;
#define int __int128
void print(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+48);
}
void solve()
{
    int x=20240601000;
    int ans=0;
    for(int i=1;i*i<x;i++)
    {//a-b          a+b-(a-b)   
        if(x%i==0&&(x/i-i)%2==0)
        {
            int b=(x/i-i)/2;
            int a=x/i-b;
            if(a*a-b*b==x)
            {
                ans+=a*a-x/2;
            }
        }
    }
    print(ans);
}
void solve1()
{
    cout<<"37044368843012180000";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve1();
    return 0;
}
