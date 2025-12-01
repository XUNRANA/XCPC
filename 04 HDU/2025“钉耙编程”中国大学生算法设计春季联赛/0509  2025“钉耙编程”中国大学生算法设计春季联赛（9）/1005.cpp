#include <bits/stdc++.h>
using namespace std;
vector<string>f,s;
int is[1000010];
void init()
{
    f.push_back("");
    f.push_back("k");
    f.push_back("g");
    f.push_back("s");
    f.push_back("z");
    f.push_back("t");

    f.push_back("n");
    f.push_back("h");
    f.push_back("b");
    f.push_back("p");
    f.push_back("m");
    f.push_back("r");

    s.push_back("a");
    s.push_back("i");
    s.push_back("u");
    s.push_back("e");
    s.push_back("o");
    s.push_back("ya");
    s.push_back("yu");
    s.push_back("yo");
    vector<string>v;
    for(auto i:f)
    {
        for(auto j:s)
        {
            v.push_back(i+j);
        }
    }

    v.push_back("wa");
    v.push_back("da");
    v.push_back("de");
    v.push_back("do");
    v.push_back("nn");

    for(auto i:v)
    {
        int res=0;
        int val=1;
        for(auto j:i)
        {
            res=res+val*(j-'a'+1);
            val=val*27;
        }
        is[res]=1;
    }
}
int fx(string s)
{
    int cnt=0;
    for(int i=0;i<s.size();)
    {
        if(i+1<s.size()&&s[i]==s[i+1])
        {
            if(s[i]=='p'||s[i]=='t'||s[i]=='k'||s[i]=='s') 
            {
                cnt++;
                i++;
                continue;
            }
        }
        
        int res=0;
        int val=1;
        for(int j=i;j<s.size();j++)
        {
            res=res+val*(s[j]-'a'+1);
            val*=27;
            if(is[res])
            {
                cnt++;
                i=j+1;
                break;
            }
        }

    }
    return cnt;
}

void solve() 
{
    string a,b;
    cin>>a>>b;
    cout<<fx(a)<<" "<<fx(b)<<"\n";
}

int main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}