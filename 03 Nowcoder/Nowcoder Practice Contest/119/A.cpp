#include <bits/stdc++.h>
using namespace std;
long long fx(long long a,long long n,long long mod)
{
    long long res=1;
    while(n)
    {
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n/=2;
    }
    return res;
}
int main()
{
    int f1,f2,p,a,n;
    cin>>f1>>f2>>p>>a>>n;
    int ans[n+1];
    ans[1]=f1;
    ans[2]=f2;
    for(int i=3;i<n+1;i++) ans[i]=(int)log2(fx(ans[i-1],ans[i-2],p)+1)+a;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    
}