#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 4010
int n,fa[N],in[N];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}

void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i,in[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='1') 
            {
                merge(i,j);
                in[j]++;
            }
        }
    }
    unordered_map<int,vector<pair<int,int>>>mp;
    for(int i=1;i<=n;i++) 
    {
        mp[find(i)].push_back({in[i],i});
        if(!in[i])//孤立点、直接一次
        {
            cout<<"1\n"<<i<<"\n";
            return ;
        }
    }
    if(mp.size()==1)//连通图 0次
    {
        cout<<"0\n";
        return ;
    }

    int mi=1e9;
    int id=0;
    for(auto &i:mp)
    {
        sort(i.second.begin(),i.second.end());//边的数量增序
        int cnt=i.second.size();
        if(cnt<mi)
        {
            mi=cnt;
            id=i.first;
        }
        for(auto j:i.second) 
        if(j.first!=cnt-1)//非完全图 选度数最少的
        {
            cout<<"1\n"<<j.second<<"\n";
            return ;
        }
        else break;
    }

    if(mp.size()==2)//两个完全图、取小的
    {
        cout<<mi<<"\n";
        for(auto j:mp[id]) cout<<j.second<<" ";
        cout<<"\n";
        return ;
    }

    cout<<"2\n";//3个以上完全图
    cout<<"1 ";
    for(int i=2;i<=n;i++) 
    if(find(i)!=find(1))
    {
        cout<<i<<"\n";
        return ;
    }

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