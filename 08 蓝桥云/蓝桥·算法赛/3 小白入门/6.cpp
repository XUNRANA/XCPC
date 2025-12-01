#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,A,B,a[1000010],c1,c2;
pair<int,int>*cnt;
int** s;
void compose(map<int,int>&cnt,ll x)
{
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            cnt[i]++;
            x/=i;
        }
    }
    if(x!=1) cnt[x]++;
}

bool check(int l,int r,int m)
{
    for(int j=0;j<m;j++)
    {
        auto [k,v]=cnt[j];
        if(s[r][j]-s[l-1][j]<v) return false;
    }
    return true;
}

ll get(map<int,int>mp)
{
    int m=mp.size();
    cnt=new pair<int,int>[m];
    int j=0;
    for(auto entry:mp) cnt[j++]=entry;
    s=new int*[n+1];
    for(int i=0;i<=n;i++) s[i]=new int[m];
    memset(s[0],0,sizeof(int)*m);
  for(int i=1;i<=n;i++) for(int j=0;j<m;j++)
  {
    auto [k,v]=cnt[j];
    int x=a[i];
    int c=0;
    while(x%k==0)
    {
      x/=k;
      c++;
    }
    s[i][j]=s[i-1][j]+c;
  }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(!check(i,n,m)) break;
        int l=i,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(i,mid,m)) r=mid-1;
            else l=mid+1;
        }
        res+=n-l+1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int>mp;
    compose(mp,A);
    c1=get(mp);
    compose(mp,B/gcd(A,B));
    c2=get(mp);
    cout<<c1-c2;
}
