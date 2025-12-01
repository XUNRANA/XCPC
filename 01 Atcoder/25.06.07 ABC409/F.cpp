#include <bits/stdc++.h>
using namespace std;

#define N 3010




int x[N],y[N];
int f[N];
int dis(int i,int j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int find(int x)
{
    return x==f[x]? x:f[x]=find(f[x]);
}
void merge(int a,int b)
{
    f[find(a)]=find(b);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<N;i++) f[i]=i;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) pq.push({dis(i,j),i,j});
    for(int i=1;i<=q;i++)
    {
        int op,x1,y1;
        cin>>op;
        if(op==1)
        {
            cin>>x1>>y1;
            x[n+1]=x1;
            y[n+1]=y1;
            for(int i=1;i<=n;i++) pq.push({dis(i,n+1),i,n+1});
            n++;
        }
        else if(op==2)
        {
            int w,fl=0;
            while(!pq.empty())
            {
                w=pq.top()[0];
                int u=pq.top()[1];
                int v=pq.top()[2];
                pq.pop();
                if(find(u)!=find(v)) 
                {
                    merge(u,v);
                    fl=1;
                    break;
                } 
            }
            
            if(!fl) 
            {
                cout<<"-1\n";
                continue;
            }
            cout<<w<<"\n";
            while(!pq.empty()&&pq.top()[0]==w) 
            {
                int u=pq.top()[1];
                int v=pq.top()[2];
                merge(u,v);
                pq.pop();
            }
        }
        else if(op==3)
        {
            cin>>x1>>y1;
            if(find(x1)==find(y1)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}