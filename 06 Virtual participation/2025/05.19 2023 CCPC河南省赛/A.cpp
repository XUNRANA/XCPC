#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(string s)
{
    string t=s;
    reverse(s.begin(),s.end());
    return s==t;
}
void solve()
{
    string s;
    cin>>s;
    set<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(st.count(s[i])) break;
        st.insert(s[i]);
        if(i+1<s.size()&&ck(s.substr(i+1)))
        {
            cout<<"HE\n";
            return ;
        }
    }
    cout<<"NaN\n";
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