#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int p,n,k;
    cin>>p>>n>>k;
    vector<int>a;
    vector<int>b;
    for(int i=1;i<=n;i++)
    {
        int op,x;
        cin>>op>>x;
        if(op) b.push_back(x);//减免
        else a.push_back(x);//优惠卷
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    vector<int>preb(b.size());
    if(b.size())
    {
        preb[0]=b[0];
        for(int i=1;i<b.size();i++) preb[i]=preb[i-1]+b[i];
    }

    int i1=0;
    double ans=p;
    double res=p;
    for(int i=0;i<=k;i++)//打折卷
    {
        int j=k-i;//优惠卷
        if(j<0) break;
        if(i>a.size()||j>b.size()) continue;
        while(i1<i) 
        {
            res*=0.1*a[i1];
            i1++;
        }
        if(j==0) ans=min(ans,res);
        else if(j>0) ans=min(ans,res-preb[j-1]);
    }
    if(ans<0) ans=0;
    printf("%.2f\n",ans);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}