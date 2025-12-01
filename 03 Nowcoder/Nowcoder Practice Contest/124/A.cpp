#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,z,a,b;
    cin>>x>>y>>z;
    b=z;
    a=max(b+x,y-b);
    if(a%z!=0) a+=z-a%z;
    cout<<a<<" "<<b<<"\n";
}