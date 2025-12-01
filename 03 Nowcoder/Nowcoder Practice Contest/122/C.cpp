#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n*m<6) cout<<"1\n";
        else if(n*m==6)
        {
            if((n==2&&m==3)||(n==3&&m==2)) cout<<2<<"\n";
            else cout<<"1\n";
        }
        else
        {
            if(n==1||m==1) cout<<"1\n";
            else if(n==2||m==2) cout<<(max(n,m)+1)/2<<"\n";
            else if(n==3&&m==3) cout<<8<<"\n";
            else cout<<n*m<<"\n";
        }
    }
}