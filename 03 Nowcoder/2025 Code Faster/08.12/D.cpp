#include <bits/stdc++.h>
using namespace std;


int is(int x)
{
    string s=to_string(x);
    string t=s;
    reverse(t.begin(),t.end());
    if(s!=t) return 0;

    for(int i=1;i<s.size();i++)
    {
        int y=s[i-1]-'0';
        int x=s[i]-'0';
        if((x&1)==(y&1)) return 0;
    }
    return 1;
}
void solve()
{
    string l,r;
    // cin>>l>>r;

    int s=0;
    for(int i=1;i<=10000000;i++)
    {
        if(is(i)) cout<<i<<"\n",s++;
    }
    //7 :1404!!
    //5 :279
    //3 :54
    //1 :9
    cout<<s<<"!!\n";
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}