#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
int res1,res2;
void fx(string s,int f)
{
    int x,y;
    int num=0;
    if(!isdigit(s[0])) num=1;
    for(auto i:s)
    {
        if(i=='d') 
        {
            x=num;
            num=0;
        }
        else num=num*10+i-'0';
    }
    y=num;
    mp[y]+=x;
    if(f) 
    {
        res1+=x;
        res2+=x*y;
    }
    else
    {
        res1-=x*y;
        res2-=x;
    }
}
void solve()
{
    string s;
    cin>>s;

    int l=0;
    vector<string>v;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-')
        {
            v.push_back(s.substr(l,i-l));
            // cout<<s.substr(l,i-l)<<"\n";
            l=i;
        }
    }
    v.push_back(s.substr(l,s.size()-l));
    
    int res=0;
    res1=res2=0;
    for(auto i:v)
    {
        if(count(i.begin(),i.end(),'d')==0) res+=stoi(i);
        else
        {
            if(i[0]=='-') fx(i.substr(1),0);
            else 
            {
                if(i[0]=='+') fx(i.substr(1),1);
                else fx(i,1);
            }
        }
    }

    res1+=res;
    res2+=res;
    for(auto i:mp) cout<<i.first<<" "<<i.second<<"\n";
    cout<<res1<<" "<<res2<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
