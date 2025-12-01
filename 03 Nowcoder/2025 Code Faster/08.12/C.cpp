#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
int a[200010];
//max
int fx1(vector<int>b)
{
    int s=0;
    for(auto i:b) s+=i;
    int ans=s;

    int p=k-1;
    int n=b.size();
    for(int i=n-1;i>=0;i--)
    {
        s+=(p-b[i])*n;
        ans=max(ans,s);
        while(i-1>=0&&b[i-1]==b[i])
        {
            s-=k;
            i--;
        }
        // 1 2 3 4 5
        // 2 3 4 5 6 7 8 9


        // 5 6 7 8 9 
        // 101

        s-=k;
        p=b[i];
    }
    return ans;
}

//min
int fx2(vector<int>b)
{
    int s=0;
    for(auto i:b) s+=i;
    int ans=s;

    int p=0;
    int n=b.size();
    for(int i=0;i<n;i++)
    {
        s-=(b[i]-p)*n;
        ans=min(ans,s);
        while(i+1<n&&b[i+1]==b[i])
        {
            s+=k;
            i++;
        }
        s+=k;
        p=b[i];
    }
    return ans;
}
void solve()
{
    int n,m;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans1=0;
    int ans2=0;
    for(int i=1;i<=m;i++)
    {
        vector<int>b;
        for(int j=i;j<=n;j+=m) b.push_back(a[j]);
        sort(b.begin(),b.end());
        ans1+=fx1(b);
        ans2+=fx2(b);
    }
    cout<<ans1<<" "<<ans2<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}