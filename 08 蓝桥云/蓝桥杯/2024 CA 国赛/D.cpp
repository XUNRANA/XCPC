#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;
void bfs()
{
    queue<string>q;
    q.push("123456789");
    mp["123456789"]=0;
    while(!q.empty())
    {
        string s=q.front();
        int c=mp[s];
        q.pop();

        string s1=s;
        swap(s1[0],s1[3]);
        swap(s1[0],s1[1]);
        swap(s1[1],s1[4]);
        if(!mp.count(s1))
        {
            mp[s1]=c+1;
            q.push(s1);
        }

        string s2=s;
        swap(s2[1],s2[4]);
        swap(s2[1],s2[2]);
        swap(s2[2],s2[5]);
        if(!mp.count(s2))
        {
            mp[s2]=c+1;
            q.push(s2);
        }

        string s3=s;
        swap(s3[3],s3[6]);
        swap(s3[3],s3[4]);
        swap(s3[4],s3[7]);
        if(!mp.count(s3))
        {
            mp[s3]=c+1;
            q.push(s3);
        }

        string s4=s;
        swap(s4[4],s4[7]);
        swap(s4[4],s4[5]);
        swap(s4[5],s4[8]);
        if(!mp.count(s4))
        {
            mp[s4]=c+1;
            q.push(s4);
        }
    }
}
void solve()
{
    string a="";
    for(int i=1;i<=9;i++) 
    {
        int x;
        cin>>x;
        a+=x+'0';
    }
    // cout<<a<<"?\n";
    cout<<mp[a]<<"\n";
}
signed main()
{
    bfs();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
