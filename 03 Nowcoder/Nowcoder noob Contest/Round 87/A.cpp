#include <bits/stdc++.h>
using namespace std;
int t,n,t1,s1,s2;
int main()
{
    cin>>t;
    while(t--)
    {
        s1=s2=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>t1;
            if(i&1) s1+=t1;
            else s2+=t1;
        }
        if(n&1)
        {
            if(s1>s2) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else
        {
            if(s2>s1) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
}