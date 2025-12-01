#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s[0]=='y') ans++;
        else if(s[0]=='z') ans+=2;
        else if(s[0]=='c') ans+=3;
        else if(s[0]=='s') ans+=4;
        else if(s[0]=='t') ans+=5;
        else if(s[0]=='l') ans+=6;
    }
    cout<<ans;
}
