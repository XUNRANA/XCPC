#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000010],b[1000010];
int f[1000010][2];
bool st[1000010];
bool check(int p)
{
    for(int i=0;i<=n;i++) for(int j=0;j<2;j++) f[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>p) 
        {
            f[i][0]=0;
            f[i][1]=-1e18;
        }
        else
        {
            f[i][1]=max(f[i-1][0],f[i-1][1])+a[i];
            f[i][0]=0;
        }
        if(max(f[i][0],f[i][1])>=m) return 1;
    }
    return 0;
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
    {
        cin>>n>>m;
        int ma=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            ma=max(ma,b[i]);
        }
        int l=1,r=ma+1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        if(l==ma+1) cout<<"-1"<<endl;
        else cout<<l<<endl;
    }
}
