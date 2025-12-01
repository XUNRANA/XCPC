#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f[10000010];
vector<int>p;
int s[400010];
int a[400010];
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e7;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e7;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
    s[0]=0;
    for(int i=1;i<=4e5;i++) s[i]=s[i-1]+p[i-1];
}
void solve() 
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    a[n+1]=0;
    for(int i=n;i>=1;i--) a[i]+=a[i+1];
    for(int i=1;i<=n;i++)
    if(a[i]>=s[n-i+1])
    {
        cout<<i-1<<"\n";
        return ;
    }
}


signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}