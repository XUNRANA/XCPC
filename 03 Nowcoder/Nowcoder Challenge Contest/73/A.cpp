#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n,ans;
    cin>>n;
    if(n&1) cout<<n*(n+1)/2;
    else 
    {
        ans=n/2;
        for(int i=n;i>=2;i--)
        {
            if(i==n/2) continue;
            if((n+1)%i==0) 
            {
                ans*=i;
                n=(n+1)/i-1;
                if(n==-1) break;
            }
        }
        cout<<ans;
    }
}