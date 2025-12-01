#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int fa[3010];
int a[60][60];
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    fa[find(x)]=find(y);
}

void solve() 
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            a[i][j]=(ch=='*');
            fa[i*m+j]=i*m+j;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]&&j+1<m&&a[i][j+1])
            {
                merge(i*m+j,i*m+j+1);
            }
            if(a[i][j]&&i+1<n&&a[i+1][j])
            {
                merge(i*m+j,(i+1)*m+j);
            }
        }
    }
    // for(int i=0;i<n;i++,cout<<"\n") for(int j=0;j<m;j++) cout<<find(i*m+j)<<" ";

    map<int,vector<array<int,2>>>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j])
            {
                mp[find(i*m+j)].push_back({i,j});
            }
        }
    }

    for(auto i:mp) 
    {
        if(i.second.size()!=3) 
        {
            cout<<"NO\n";
            return ;
        }
        else
        {
            map<int,int>m1,m2;
            for(auto j:i.second)
            {
                m1[j[0]]++;
                m2[j[1]]++;
            }
            if(m1.size()!=2&&m2.size()!=2)
            {
                cout<<"NO\n";
                return ;
            }
        }   
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j])
            for(int k=0;k<4;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni<0||ni>=n||nj<0||nj>=m) continue;
                if(a[ni][nj]&&find(ni*m+nj)!=find(i*m+j))
                {
                    cout<<"NO\n";
                    return  ;
                }
            }
        }
    }
    cout<<"YES\n";
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