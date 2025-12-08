#include <bits/stdc++.h>
using namespace std;
string fx(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size()) a+="0";
    while(b.size()<a.size()) b+="0";
    int c=0;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
        int x=a[i]-'0';
        int y=b[i]-'0';
        ans+=(x+y+c)%2+'0';
        c=(x+y+c)/2;
    }
    if(c) ans+="1";
    reverse(ans.begin(),ans.end());
    return ans;
}
void solve()
{
    string s;
    cin>>s;
    //16+4+1
    cout<<fx(fx(s+"0000",s+"00"),s)<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}