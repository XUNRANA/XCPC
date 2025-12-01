#include <bits/stdc++.h>
using namespace std;
int x,n,a,mx;
char ch,mxch;
int main()
{
    cin>>x>>n;
    mx=0;
    ch='a';
    while(n--)
    {
        cin>>ch>>a;
        if(a>mx)
        {
            mxch=ch;
            mx=a;
        }
    }
    for(int i=0;i<1000;i++) cout<<mxch;
}