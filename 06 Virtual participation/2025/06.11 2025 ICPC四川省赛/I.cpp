#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt;
int nex[300010][26];
void insert(string s)
{
    int now=0;
    for(auto i:s)
    {
        if(!nex[now][i-'a']) 
        {
            nex[now][i-'a']=++cnt;
        }
        now=nex[now][i-'a'];
    }
}

void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        insert(s);
    }
    cout<<cnt<<"\n";
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