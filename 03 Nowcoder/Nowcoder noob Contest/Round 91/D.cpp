#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s0,s1,ans;
string s;
#define P 1000000007
signed main()
{
    cin>>n>>s;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]-'0')%2==0)
        {
            if(s[i]-'0'==0) 
            {
                ans+=s0+s1+1;//0+以奇数结尾、0+以偶数结尾、0
                s0=2*s0+s1;//更新偶数结尾的个数
                s0%=P;
                ans%=P;
            }
            else
            {
                ans+=s1+s0+1;
                s0=s0*2+s1+1;
                s0%=P;
                ans%=P;
            }
        }
        else 
        {
            s1=s1*2+s0+1;//更新奇数结尾的个数
            s1%=P;
        }
        //cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}