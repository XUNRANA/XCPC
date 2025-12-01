#include <bits/stdc++.h>
using namespace std;



//j: 0 3 6
string f1(string a,int j)
{
    // 0->1 1->2 2->0
    char t=a[j+2];
    a[j+2]=a[j+1];
    a[j+1]=a[j];
    a[j]=t;
    return a;
}

//j:0 1 2 
string f2(string a,int j)
{
    int t=a[j+6];
    a[j+6]=a[j+3];
    a[j+3]=a[j];
    a[j]=t;
    return a;
}
int c[]={6,3,0,7,4,1,8,5,2};
string f3(string a)
{
    string b="123456789";
    for(int i=0;i<9;i++) b[i]=a[c[i]];
    return b;
}
map<string,int>mp;
void bfs()
{
    queue<string>q;
    q.push("123456789");
    mp["123456789"]=0;
    while(!q.empty())
    {
        string a=q.front();
        int c=mp[a];
        q.pop();
        string t=f1(a,0);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

        t=f1(a,3);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

        t=f1(a,6);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }
        
        t=f2(a,0);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

        t=f2(a,1);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

        t=f2(a,2);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

        t=f3(a);
        if(!mp.count(t)) 
        {
            mp[t]=c+1;
            q.push(t);
        }

    }
}
int change[10];
void solve()
{
    string a,b,t;
    for(int i=1;i<=3;i++)
    {
        cin>>t;
        a+=t;
    }
    for(int i=1;i<=3;i++)
    {
        cin>>t;
        b+=t;
    }
    for(int i=0;i<9;i++) change[a[i]-'0']=i+1;
    for(int i=0;i<9;i++) b[i]=char(change[b[i]-'0']+'0');
    if(mp.count(b)) cout<<mp[b]<<"\n";
    else cout<<"-1\n";
} 

int main()
{
    bfs();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}

