#include <bits/stdc++.h>
using namespace std;
long long t,n,mx,t1;
int main()
{
    cin>>t;
    while(t--)
    {
        int f=0;
        cin>>n>>mx;
        for(int i=2;i<=n-1;i++)
        {
            cin>>t1;
            if(t1!=mx) f=1;
            if(t1>mx) mx=t1;
        }
        if(f==0) cout<<1<<"\n";
        else cout<<mx<<"\n";
    }
}