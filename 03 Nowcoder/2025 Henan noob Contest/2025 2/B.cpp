#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
int inv(int x)
{
    return ksm(x,P-2);
}

int fx1(int x,int i)//1到x在第i位为1的数量
{
    int r=1ll<<(i+1);
    int s=1ll*(x+1)/r*(r/2);
    s+=max((x+1)%r-r/2,0ll);
    return s;
//     0000
//     0001
//     0010
//     0011
//     0100
//     0101
//     0110
//     0111
//     1000
//     1001
//     1010
//     1011
//     1100
//     1101
//     1110
//     1111
//    10000
}

void solve()
{
    int l,r,y;
    cin>>l>>r>>y;
    int s=0;
    for(int i=0;i<32;i++) 
    {
        int c1=fx1(r,i)-fx1(l-1,i);
        int c0=(r-l+1)-c1;
        
        if(y>>i&1) s+=c0;
        else s+=c1;
    }

    cout<<s%P*inv(r-l+1)%P<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}

