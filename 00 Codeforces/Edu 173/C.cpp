#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],p[200010];
pair<int,int> fx(int l,int r)
{
    int mx=0,mi=0;
    int s1=0,s2=0;
    for(int i=l;i<=r;i++)
    {
        s1+=a[i];
        s2+=a[i];
        mx=max(mx,s1);
        mi=min(mi,s2);
        if(s1<0) s1=0;
        if(s2>0) s2=0;
    }
    return {mi,mx};
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]+a[i];

    vector<pair<int,int>>ans,res;
    
    for(int i=1;i<=n;i++)
    if(a[i]!=1&&a[i]!=-1)
    {
        int m1=0,m2=0;
        int m3=0,m4=0;
        for(int j=1;j<=n;j++)
        {
            if(j<i)
            {
                m1=min(m1,p[i-1]-p[j-1]);
                m2=max(m2,p[i-1]-p[j-1]);
            }
            else if(j>i)
            {
                m3=min(m3,p[j]-p[i]);
                m4=max(m4,p[j]-p[i]);
            }
        }
        ans.push_back(fx(1,i-1));
        ans.push_back(fx(i+1,n));
        ans.push_back({m1+m3+a[i],a[i]+m2+m4});
        set<int>st;
        for(auto j:ans) for(int i=j.first;i<=j.second;i++) st.insert(i);
        cout<<st.size()<<"\n";
        for(auto i:st) cout<<i<<" ";
        cout<<"\n";
        return ;
    }



    int mi=fx(1,n).first;
    int mx=fx(1,n).second;
    cout<<mx-mi+1<<"\n";
    for(int i=mi;i<=mx;i++) cout<<i<<" ";
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

