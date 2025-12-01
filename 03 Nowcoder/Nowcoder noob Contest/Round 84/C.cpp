#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,f,x,n,k,a[200010];
int main()
{
    cin>>t;
    while(t--)
    {
        x=-1e10;
        f=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(x-a[i]>k)
            {
                f=1;
                break;
            }
            x=max(x,a[i]-k);
        }
        if(f==1) cout<<"No\n";
        else cout<<"Yes\n";
    }
}