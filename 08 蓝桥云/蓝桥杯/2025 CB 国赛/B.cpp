#include <bits/stdc++.h>
using namespace std;
#define int long long

int C(int x)
{
    return x*(x-1)/2;
}
bool ck(int a,int b,int c)
{
    int a1=a*b;
    int b1=C(a+b+c);
    int g=__gcd(a1,b1);
    a1/=g;
    b1/=g;
    if(a1!=517||b1!=2091) return 0;


    a1=b*c;
    b1=C(a+b+c);
    g=__gcd(a1,b1);
    a1/=g;
    b1/=g;
    if(a1!=2632||b1!=10455) return 0;


    a1=a*c;
    b1=C(a+b+c);
    g=__gcd(a1,b1);
    a1/=g;
    b1/=g;
    if(a1!=308||b1!=2091) return 0;

    return 1;
}
void solve()
{
    // for(int i=1;i<=200;i++)
    // {
    //     for(int j=1;j<=200;j++)
    //     {
    //         for(int k=1;k<=200;k++)
    //         {
    //             if(ck(i,j,k)) 
    //             {
    //                 cout<<i<<" "<<j<<" "<<k<<"\n";
    //             }
    //         }
    //     }
    // }
    cout<<"55,94,56";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}