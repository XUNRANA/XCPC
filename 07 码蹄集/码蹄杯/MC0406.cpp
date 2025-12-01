#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353

bool f[100001];
vector<int>p1;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e5;i++)
	{
		if(!f[i]) p1.push_back(i);
		for(int j=0;j<p1.size()&&p1[j]*i<=1e5;j++)
		{
			f[p1[j]*i]=1;
			if(i%p1[j]==0) break;
		}
	}
}

vector<int>p;
int n;
set<int>st;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    map<int,int>mp;
    for(auto i:st)
    {
        for(auto j:p1)
        {
            if(i%j==0)
            {
                int c=0;
                while(i%j==0) i/=j,c++;
                if(mp.count(j)) mp[j]=max(mp[j],c);
                else mp[j]=c;
            }
        }
        if(i!=1) 
        {
            if(mp.count(i)) mp[i]=max(mp[i],1ll);
            else mp[i]=1;
        }
    }
    int ans=1;
    for(auto i:mp) 
    {
        int x=i.first;
        int c=i.second;
        while(c--) ans=ans*x%P;
    }
    cout<<ans<<"\n";
}
signed main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

