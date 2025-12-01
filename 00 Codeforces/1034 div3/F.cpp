#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010];
int vt[100010];

int f[100010];
vector<int>p;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e5;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e5;j++)
		{
			f[p[j]*i]=p[j];
			if(i%p[j]==0) break;
		}
	}
    // for(int i=0;i<100;i++) cout<<i<<" "<<f[i]<<"\n";
}

void solve()
{
    cin>>n;
    // 1 4 3 2
    if(n<=3) for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
    else 
    {
        for(int i=1;i<=n;i++) 
        {
            a[i]=i;
            vt[i]=0;
        }
        // for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
        
        for(int i=2;i<=n;i++)
        {
            if(!f[i])
            {
                if(2*i<=n)
                {
                    swap(a[i],a[2*i]);
                    vt[i]=vt[2*i]=1;
                }
            }
            else 
            {
                if(!vt[i]) swap(a[i],a[f[i]]);
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    } 
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}