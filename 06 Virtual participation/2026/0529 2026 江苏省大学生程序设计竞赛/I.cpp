#include <bits/stdc++.h>
using namespace std;

int ss[26][2];
int tt[26][2];
void solve()
{
    string s,t;
    cin>>s>>t;
    for(int i=0;i<26;i++) ss[i][0]=ss[i][1]=-1;
    for(int i=0;i<26;i++) tt[i][0]=tt[i][1]=-1;

    for(int i=0;i<s.size();i++) 
    {
        if(ss[s[i]-'a'][0]==-1) ss[s[i]-'a'][0]=i;
        ss[s[i]-'a'][1]=i;
    }
    for(int i=0;i<t.size();i++)
    {
        if(tt[t[i]-'a'][0]==-1) tt[t[i]-'a'][0]=i;
        tt[t[i]-'a'][1]=i;
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(ss[i][0]!=-1&&ss[j][1]!=-1&&ss[i][0]<ss[j][1]&&tt[i][0]!=-1&&tt[j][1]!=-1&&tt[i][0]<tt[j][1])
            {
                cout<<char(i+'a')<<char(j+'a')<<"\n";
                return ;
            }
        }
    }

    cout<<"HENG!\n";
    


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}