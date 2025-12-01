#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
int a[N];
int f[N],g[N];//长度为i的LIS结尾元素的最小值, 到i为止的LIS的长度最大值
vector<int>rp;//维护放R的数的下标
int res[N];
int ans;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++)
    {//枚举R开始的第一个点，跑LIS
        int l=0;
        for(int j=i;j<=n;j++)
        {
            if(!l) 
            {
                f[++l]=a[j];
                g[j]=l;
            }
            else
            {
                if(a[j]>f[l])
                {
                    f[++l]=a[j];
                    g[j]=l;
                }
                else if(a[j]>f[1])
                {
                    int x=lower_bound(f+1,f+1+l,a[j])-f;
                    f[x]=a[j];
                    g[j]=x;
                }
            }
        }
        vector<int>tmp;//统计该LIS用了哪些数
        int cnt=l,l1=0;
        for(int j=n;j>=1;j--)
        {
            if(g[j]==cnt&&cnt) 
            {
                tmp.push_back(j);
                cnt--;
            }
            g[j]=0;
        }
        sort(tmp.begin(),tmp.end());
        for(auto j:tmp) res[j]=1;
        //剩余的[1,r-1]的数，即l部分，尝试续接上面的最LIS
        int x=f[1];//LIS的末位值，比他小就能接
        if(!l) x=1e18;
        for(int j=n;j>=1;j--)
        {
            if(res[j]==1)
            {
                res[j]=0;
                continue;
            }
            if(l1==0&&a[j]<x)
            {
                f[++l1]=a[j];
            }
            else if(a[j]<x)
            {
                if(a[j]>f[l1]) f[++l1]=a[j];
                else
                {
                    int x=lower_bound(f+1,f+l1+1,a[j])-f;
                    f[x]=a[j];
                }
            }
        }

        if(l+l1>ans) 
        {
            ans=l+l1;
            rp=tmp;
        }
        else if(l+l1==ans)
        {
            if(rp.size()==0) continue;
            if(tmp.size()==0) rp=tmp;
            else if(tmp>rp) rp=tmp;
        }
    }
    cout<<ans<<"\n";
    for(auto i:rp) res[i]=1;
    for(int i=1;i<=n;i++)
    if(res[i]) cout<<"R";
    else cout<<"L";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
