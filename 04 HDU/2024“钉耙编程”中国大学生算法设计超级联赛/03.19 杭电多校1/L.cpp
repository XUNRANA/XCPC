#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define N 4010
struct node
{
    int a,b,c,d;
}p[N];
int C[N][N];
short ma[N<<1][N<<1];
int ans[N],sum[N],a[N<<3],b[N<<3],aid[N<<3],bid[N<<3];
int t1,t2;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        b>>=1;
        a=a*a%P;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        if(!j) C[i][j]=1;
        else C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d;
        p[i].a+=5;
        p[i].b+=5;
        p[i].c+=5;
        p[i].d+=5;
        p[i].c--;
        p[i].d--;
        a[++t1]=p[i].a;
        a[++t1]=p[i].c;
        a[++t1]=p[i].a-1;
        a[++t1]=p[i].c+1;
        b[++t2]=p[i].b;
        b[++t2]=p[i].d;
        b[++t2]=p[i].b-1;
        b[++t2]=p[i].d+1;
    }
    sort(a+1,a+1+t1);
    sort(b+1,b+1+t2);
    int l1=unique(a+1,a+1+t1)-(a+1);
    int l2=unique(b+1,b+1+t2)-(b+1);
    for(int i=1;i<=n;i++)
    {
        p[i].a=lower_bound(a+1,a+l1+1,p[i].a)-a;
        p[i].c=lower_bound(a+1,a+l1+1,p[i].c)-a;
        p[i].b=lower_bound(b+1,b+l2+1,p[i].b)-b;
        p[i].d=lower_bound(b+1,b+l2+1,p[i].d)-b;
        ma[p[i].a][p[i].b]++;
        ma[p[i].a][p[i].d+1]--;
        ma[p[i].c+1][p[i].b]--;
        ma[p[i].c+1][p[i].d+1]++;
    }
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            ma[i][j]+=ma[i-1][j]+ma[i][j-1]-ma[i-1][j-1];
            if(ma[i][j]>=1)
            {
                sum[ma[i][j]]+=(a[i+1]-a[i])*(b[j+1]-b[j])%P;
                sum[ma[i][j]]%=P;
            }
        }
    }
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++)
        {
            if(n-j>=i) ans[i]+=sum[j]*((C[n][i]-C[n-j][i]+P)%P)%P;
            else ans[i]+=sum[j]*C[n][i]%P;
            ans[i]%=P;
        }
        cout<<ans[i]*ksm(C[n][i],P-2)%P<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}