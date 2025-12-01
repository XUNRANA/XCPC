#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    map<char,int>cnt;
    int f=0;
    char a,b,c;
    for(int i=0;i<n;i++)
    {
        cnt[s[i]]++;
        if(f==0&&cnt[s[i]]==5)
        {
            a=s[i];
            cnt.clear();
            f++;
        }
        if(f==1&&cnt[s[i]]==7)
        {
            b=s[i];
            cnt.clear();
            f++;
        }
        if(f==2&&cnt[s[i]]==5)
        {
            c=s[i];
            cnt.clear();
            f++;
        }
    }
    if(f<3) cout<<"none\n";
    else
    {
        for(int i=1;i<=17;i++)
        if(i<=5) cout<<a;
        else if(i<=12) cout<<b;
        else cout<<c;
        cout<<"\n";
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
