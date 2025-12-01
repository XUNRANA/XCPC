#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool beat(char c1,char c2)
{
    if(c1=='S') return c2=='P';
    if(c1=='P') return c2=='R';
    if(c1=='R') return c2=='S'; 
}
void solve() 
{
    string s;
    cin>>s;
    int ans=0;
    int mx=0;
    int idx=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1]) continue;
        if(beat(s[i],s[i-1])) ans++;
        else ans--;
        if(ans>mx)//净胜最多的获胜
        {
            mx=ans;
            idx=i;
        }
    }
    cout<<s[idx]<<"\n";
}

int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}