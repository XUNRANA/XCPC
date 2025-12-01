#include <bits/stdc++.h>
using namespace std;
#define N 300010
int fa[2*N],a[N],cnt[2*N];
int find(int x)
{
    return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
    fa[find(u)]=find(v);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=m/(n-1)+1;i++) for(int j=1;j<=n;j++) fa[i*n+j]=i*n+j;
    for(int i=0;i<=2*m;i++) cnt[i]=0;
    for(int i=0;i<=m;i++) a[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int l=0,r=m/(n-1)+1;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(find(mid*n+u)==find(mid*n+v)) l=mid+1;
            else r=mid-1;
        }
        merge(l*n+u,l*n+v);
        a[i]=l+1;
        cnt[l+1]++;
    }

    for(int i=1;i<=m;i++) 
    {
        if(cnt[a[i]]!=n-1) a[i]=-1;
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve(); 
}