#include<bits/stdc++.h> 

using namespace std;
#define int long long
signed main( )
{
    int n;
    cin>>n;
    int ans=2,j=5;
    for(int i=1;i<=n-1;i++)
    {
        ans+=j;
        j+=4;
    }
    cout<<ans<<"\n";
}

// 1 2
// 2 7
// 3 16
