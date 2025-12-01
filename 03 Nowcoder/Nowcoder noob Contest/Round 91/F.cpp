#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],s0,s1,ans;
#define P 1000000007
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=0;j<=20;j++)
    {
        s1=s0=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>>j&1)
            {
                ans=(ans+s0*(n-i+1)%P*2%P*(1<<j)%P)%P;
                s1+=i;
                s1%=P;
            }
            else
            {
                ans=(ans+s1*(n-i+1)%P*2%P*(1<<j)%P)%P;
                s0+=i;
                s0%=P;
            }
        }
    }
    cout<<ans<<"\n";
}