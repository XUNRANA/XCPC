#include <bits/stdc++.h>
using namespace std;
int main()
{
    int f=0;
    string s,t="";
    char ch;
    while(cin>>s)
    {
        int c=0;
        if(f==1) cout<<" ";
        for(auto i:s)
        {
            if(i=='6') c++;
            else
            {
                if(c<=3) while(c--) cout<<"6";
                else if(c<=9) cout<<"9";
                else cout<<"27";
                c=0;
                cout<<i;
            }
        }
        if(c<=3) while(c--) cout<<"6";
        else if(c<=9) cout<<"9";
        else cout<<"27";
        f=1;
    }
    while((ch=getchar())==' ') t+=ch;
    cout<<t;
}
