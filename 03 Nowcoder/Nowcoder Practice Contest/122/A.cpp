#include <bits/stdc++.h>
using namespace std;
int t,n,c1,c0,t1;
int main()
{
    cin>>t>>n;
    while(t--)
    {
        c1=c0=0;
        for(int i=1;i<=n;i++)
        {
            cin>>t1;
            if(t1==1) c1++;
            else c0++;
        }
        cout<<abs(c1-c0)<<"\n";
    }
}