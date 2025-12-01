#include <bits/stdc++.h>
using namespace std;
#define int long long

int k;
string s;
vector<string>a;
void init()
{
    a.push_back("lose");
    
    a.push_back("ose");
    a.push_back("lse");
    a.push_back("loe");
    a.push_back("los");

    a.push_back("lo");
    a.push_back("ls");
    a.push_back("le");
    a.push_back("os");
    a.push_back("oe");
    a.push_back("se");

    a.push_back("l");
    a.push_back("o");
    a.push_back("s");
    a.push_back("e");
}
void solve()
{
    cin>>k;
    cin>>s;
    vector<int>b;
    for(int i=0;i<s.size();i++)
    {
        for(auto j:a)
        {
            if(i+j.size()-1<s.size()&&s.substr(i,j.size())==j)
            {
                b.push_back(4-j.size());
                i+=j.size()-1;
                break;
            }
        }
    }
    sort(b.begin(),b.end());
    int ans=0;
    for(auto i:b)
    {
        if(k>=i)
        {
            k-=i;
            ans++;
        }
    }
    cout<<ans+k/4<<"\n";
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}