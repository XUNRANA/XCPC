#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
#define P1 13331
int hz[100010];
int hf[100010];
int p[100010];
int n;
int getz(int l,int r)
{
    if(l>r) return 0;
    return (hz[r]-hz[l-1]*p[r-l+1]%P+P)%P;
}
int getf(int l,int r)
{
    if(l>r) return 0;
    return (hf[l]-hf[r+1]*p[r-l+1]%P+P)%P;
}
bool ck(int l,int r)
{
    int a=getz(1,l-1);
    int a1=getf(1,l-1);
    int l1=l-1;

    int b=getf(l,r);
    int b1=getz(l,r);
    int l2=r-l+1;
    
    int c=getz(r+1,n);
    int c1=getf(r+1,n);
    
    int l3=n-r;
    int res1=((a*p[l2+l3]%P+b*p[l3]%P)%P+c)%P;
    
    int res2=(a1+(b1*p[l1]%P+c1*p[l1+l2]%P)%P)%P;

    return res1==res2;
}
void solve() 
{
    string s;
    cin>>s;
    n=s.size();
    s=" "+s;
    p[0]=hz[0]=1;
    for(int i=1;i<=n;i++)
    {
        hz[i]=(hz[i-1]*P1%P+s[i])%P;
        p[i]=p[i-1]*P1%P;
    }
    hf[n+1]=1;
    for(int i=n;i>=1;i--) hf[i]=(hf[i+1]*P1%P+s[i])%P;
    if(hz[n]==hf[1]) 
    {
        cout<<1<<" "<<n<<"\n";
        return ;
    }
    int i=1,j=n;
    while(s[i]==s[j]) i++,j--;
    
    
    for(int r=i+1;r<=n;r++) if(ck(i,r))
    {
        cout<<i<<" "<<r<<"\n";
        return ;
    }

   
    for(int l=j-1;l>=1;l--) if(ck(l,j))
    {
        cout<<l<<" "<<j<<"\n";
        return ;
    }
   
    cout<<"-1 -1\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}