#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int f[1000010];
vector<int>p;
ull rd[1000010];
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e6;i++)
	{
		if(!f[i]) 
        {
            rd[i]=rng();
            p.push_back(i);
            for(int j=i+i;j<=1e6;j+=i)
            {
                f[j]=1;
                int t=j;
                int c=0;
                while(t%i==0)
                {
                    t/=i;
                    c++;
                }
                if(c&1) rd[j]^=rd[i];
            }
        }
	}
    // for(int i=0;i<=20;i++) cout<<i<<" "<<rd[i]<<"\n";
}

void solve() 
{
    int n;
    cin>>n;
    unordered_map<ull,int>mp;
    ull res=0;
    mp[res]=1;
    int ans=0,l=-1,r=-1;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        res^=rd[x];
        if(mp.count(res)) 
        {
            if(i-mp[res]+1>ans)
            {
                ans=i-mp[res]+1;
                l=mp[res];
                r=i;
            }
        }
        else mp[res]=i+1;
    }
    cout<<l<<" "<<r<<"\n";
}

int main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}