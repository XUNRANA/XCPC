#include <bits/stdc++.h>
using namespace std;
#define int long long  
#define P 1000000007
int C[1010][1010];
void init()
{
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j) C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
        }
    }
}
void solve()
{
    init();
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x+y;i++)
	{
		int c1=i/2,c2=i-c1;
        cout<<(C[x-1][c1-1]*C[y-1][c2-1]%P+C[x-1][c2-1]*C[y-1][c1-1]%P)%P<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}




/*
#include <bits/stdc++.h>
using namespace std;
#define int long long  
#define P 1000000007
int ans[2010],jc[2010],inv[2010];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=2000;i++) jc[i]=jc[i-1]*i%P;
	inv[2000]=ksm(jc[2000],P-2);
	for(int i=2000-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%P;
}
int C(int a,int b)
{
	if(a<0||b<0||b>a) return 0;
	return jc[a]*inv[b]%P*inv[a-b]%P;
}
void solve()
{
    init();
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x+y;i++)
	{
		int c1=i/2,c2=i-c1;
		ans[i]=(C(x-1,c1-1)*C(y-1,c2-1)%P+C(x-1,c2-1)*C(y-1,c1-1)%P)%P;
	}
	for(int i=1;i<=x+y;i++) cout<<ans[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

*/

