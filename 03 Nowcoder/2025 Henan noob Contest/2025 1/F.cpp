#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,s,x;
    cin>>n>>s>>x;
    //n个数
    //sum ==s
    //xor ==x
    if(n==1)
    {
        if(s==x) cout<<s<<"\n";
        else cout<<"zetsubou\n";
    }
    else //n>=2
    {
        if(s==x) 
        {
            cout<<s<<" ";
            n--;
            while(n--) cout<<"0 ";
            cout<<"\n";
        }
        else if(s<x) cout<<"zetsubou\n";
        else//s >x 
        {
            if(n==2)
            {
                if((s-x)%2==1||(((s-x)/2)&x)) cout<<"zetsubou\n";
                else cout<<x+(s-x)/2<<" "<<(s-x)/2<<"\n";
            }
            else //n>2
            {
                if((s-x)%2==0) 
                {
                    cout<<x<<" "<<(s-x)/2<<" "<<(s-x)/2<<" "<<" ";
                    n-=3;
                    while(n--) cout<<"0 ";
                    cout<<"\n";
                }
                else cout<<"zetsubou\n";
            }            
        }
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}