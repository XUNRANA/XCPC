#include <bits/stdc++.h>
using namespace std;
bool f[100010];
vector<int>p;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e5;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e5;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
//  贝特朗假设：对任一实数 x≥1，在 x 及 2x 之间必有一素数。
void solve()
{
    int n;
    cin>>n;
    if(n==2) cout<<"2 1\n";
    else 
    {
        int x=*lower_bound(p.begin(),p.end(),n/3);
        cout<<x<<" ";
        int l,r;
        for(l=x-1,r=x+1;l>=1&&r<=n;l--,r++)
        cout<<l<<" "<<r<<" ";
        for(int i=1;i<=l;i++) cout<<i<<" ";
        for(int i=r;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
    }
}

int main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
