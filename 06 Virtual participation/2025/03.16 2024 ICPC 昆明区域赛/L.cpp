
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int b[500010];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int cnt=0;//攻击次数
    if(a[1]==1) 
    {
        a[1]--;
        cnt++;
    }
    for(int i=1;i<=n;i++)
    if(a[i]>1)
    {
        cnt++;
        a[i]--;
    }

    int tot=0;//死亡人数
    for(int i=1,j=1;i<=m;i++)//遍历每一个b士兵
    {
        while(j<=n&&a[j]<=tot)//a士兵死亡、死亡人数增加 
        {
            j++;
            tot++;
        }
        if(b[i]>tot) cnt-=b[i]-tot;//血量大于死亡人数、需要消耗攻击次数
        tot++;//b死亡 
    }
    if(cnt<0) cout<<"No\n";//攻击次数消耗完  无解
    else cout<<"Yes\n";
} 
 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}