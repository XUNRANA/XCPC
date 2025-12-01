#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,q;
    string s;
    cin>>n>>q>>s;
    vector<set<int>>g(4);
    //0 b-a
    //1 c-a
    //2 c-b
    //3 b-c
    for(int i=0;i<q;i++)
    {
        char a,b;
        cin>>a>>b;
        if(a=='a'||a==b) continue;
        if(b=='a')
        {
            if(a=='b') g[0].insert(i);
            else g[1].insert(i);
        }
        else
        {
            if(a=='b') g[3].insert(i);
            else g[2].insert(i);
        }
    }
    //0 b-a
    //1 c-a
    //2 c-b
    //3 b-c
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') continue;
        if(s[i]=='b')
        {
            if(!g[0].empty())
            {
                //b-a
                s[i]='a';
                auto it=g[0].begin();
                g[0].erase(it);
            }
            else if(!g[3].empty())
            {
                //b-c-a
                auto it=g[3].begin();
                auto it1=g[1].upper_bound(*it);
                if(it1!=g[1].end())
                {
                    s[i]='a';
                    g[3].erase(it);
                    g[1].erase(it1);
                }
            }
        }
        else if(s[i]=='c')
        {
            //c-a
            if(!g[1].empty())
            {
                s[i]='a';
                auto it=g[1].begin();
                g[1].erase(it);
            }
            else if(!g[2].empty())
            {
                //c-b-a
                auto it=g[2].begin();
                auto it1=g[0].upper_bound(*it);
                if(it1!=g[0].end())
                {
                    s[i]='a';
                    g[2].erase(it);
                    g[0].erase(it1);
                }
                else
                {
                    s[i]='b';
                    g[2].erase(it);
                }
            }
        }
    }
    cout<<s<<"\n";
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