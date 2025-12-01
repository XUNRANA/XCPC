#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    int sc=0;
    int sum=0;
    int cnt=0;
    while(getline(cin,s))
    {
        s=" "+s+" ";
        int f1=0,f2=0,f3=0;

        for(auto i:s)
        if(islower(i))
        {
            f1++;
        }
        else if(isupper(i))
        {
            f2++;
        }
        else if(isdigit(i))
        {
            f3++;
        }
        else
        {
            if(f1||f2||f3)
            {
                cnt++;
                sum+=f1+f2+f3;
                if(f1&&f2&&f3) sc+=5;
                else if(f3&&(f1||f2)) sc+=3;
                else if(f1&&f2) sc++;
            }
            f1=f2=f3=0;
        }
    }
    cout<<sc<<"\n";
    cout<<sum<<" "<<cnt<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}