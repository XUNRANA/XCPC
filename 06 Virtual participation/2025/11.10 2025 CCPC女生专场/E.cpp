#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[1000010];//满x减c[x] 
int d[1000010];//不使用折扣，最多满减多少
int pmxd[1000010];

//ST表，快速查询区间最大值/最小值 
int f[1000010][22]; 
int query(int l,int r)
{
	int k=log2(r-l+1);//求区间长度 
	return min(f[l][k],f[r-(1<<k)+1][k]);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        c[a]=max(c[a],b);
    }
    for(int i=1;i<=1000000;i++)
    {
        if(c[i])
        {
            for(int j=1;j*i<=1000000;j++)
            d[j*i]=max(d[j*i],c[i]*j);
        }
    }
    for(int i=1;i<=1000000;i++) pmxd[i]=max(pmxd[i-1],d[i]);


    for(int i=1;i<=1000000;i++) f[i][0]=i-pmxd[i];

    for(int i=1;i<=21;i++) 
    for(int j=1;j+(1<<i)-1<=1000000;j++)
    f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);//动态规划更新 




    while(n--)
    {
        int w,p,q;
        cin>>w>>p>>q;
        
        int b1=w*p;
        int a1=q;
        int g=__gcd(a1,b1);
        b1/=g;
        a1/=g;
        b1-=pmxd[b1/a1]*a1;
        int l=(w*p+q-1)/q;
        int b2=query(l,w);
        int a2=1;
        if(b1*a2<a1*b2) cout<<b1<<" "<<a1<<"\n";
        else cout<<b2<<" "<<a2<<"\n";       
    }
}
signed main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}