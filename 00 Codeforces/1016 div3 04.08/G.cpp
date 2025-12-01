#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int idx,cnt;
int rt[N];
int siz[N*32];
int ch[N*32][2];
void insert(int v)
{
    rt[++idx]=++cnt;//新根开点
    int x=rt[idx-1];//旧版
    int y=rt[idx];//新版
    for(int i=30;i>=0;i--)
    {
        int j=v>>i&1;
        ch[y][!j]=ch[x][!j];//异位继承
        ch[y][j]=++cnt;//新位开点
        x=ch[x][j];
        y=ch[y][j];
        siz[y]=siz[x]+1;//新位多1
    }
}
int query(int x,int y,int v)
{
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        int j=v>>i&1;
        if(siz[ch[y][!j]]>siz[ch[x][!j]])
        {
            y=ch[y][!j];
            x=ch[x][!j];
            ans+=1<<i;
        }
        else
        {
            y=ch[y][j];
            x=ch[x][j];
        }
    }
    return ans;
}
int n,k,x;
void solve()
{
	idx=cnt=0;
	cin>>n>>k;
	int l=1;
	int ans=1e18;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		insert(x);
		while(l<=i&&query(rt[l-1],rt[i],x)>=k)
		{
			ans=min(ans,i-l+1);
			l++;
		}
	}
	if(ans==1e18) ans=-1;
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

