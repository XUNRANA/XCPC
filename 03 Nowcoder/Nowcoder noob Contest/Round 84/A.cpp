#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,X,Y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>X>>Y;
        if(Y<X) cout<<"No\n";
        else if(Y-X<=n-m) cout<<"Yes\n";
        else cout<<"No\n";
    }
}