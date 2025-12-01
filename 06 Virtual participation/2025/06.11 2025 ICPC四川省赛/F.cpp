#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int f(int x)
{
    int c1=0,ans=0;
    for(auto i:s)
    {
        if(i=='1') c1++;
        else if(i=='0') ans+=c1;
        else if(i=='?') 
        {
            if(x) x--,c1++;
            else ans+=c1;
        }
    }
    return ans;
}
void solve()
{
    int m;
    cin>>m>>s;
    int n=count(s.begin(),s.end(),'?');
    int L=0,R=n;
    while(L<R)
    {
        int m1=L+(R-L)/3;
        int m2=R-(R-L)/3;
        if(f(m1)>f(m2)) R=m2-1;//f(m1)<f(m2) 极大值时刚好相反 
        else L=m1+1;
    }
    cout<<f(L)<<"\n";//f（L）即为函数极小值
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}