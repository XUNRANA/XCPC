#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int jc[100010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
}
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
int inv(int x)
{
	return ksm(x,P-2);
}
int C(int a,int b)
{
	return jc[a]*inv(jc[b]*jc[a-b]%P)%P;
}
void solve()
{
	int n,x,y;
	string s;
	cin>>n>>x>>y>>s;
	vector<int>c(4,0);
	for(auto i:s)
	{
		if(i=='U') c[2]++;
		else if(i=='D') c[3]++;
		else if(i=='L') c[0]++;
		else c[1]++;
	}
	int ans=1;
	if(x<0)
	{
		if(c[3]<-x) 
		{
			cout<<"NO\n";
			return ;
		} 
		else 
        {
            int res=0;
            for(int i=-x,j=0;i<=c[3]&&j<=c[2];i++,j++)
            res=(res+C(c[3],i)%P*C(c[2],j)%P)%P;
            ans=ans*res%P;
        }
	}
	
	if(x>0)
	{
		if(c[2]<x)
		{
			cout<<"NO\n";
			return ;
		}
		else 
        {
            int res=0;
            for(int i=x,j=0;i<=c[2]&&j<=c[3];i++,j++)
            res=(res+C(c[2],i)%P*C(c[3],j)%P)%P;
            
            ans=ans*res%P;
        }
	}
	
	if(y<0)
	{
		if(c[0]<-y) 
		{
			cout<<"NO\n";
			return ;
		} 
		else 
        {
            int res=0;
            for(int i=-y,j=0;i<=c[0]&&j<=c[1];i++,j++)
            res=(res+C(c[0],i)%P*C(c[1],j)%P)%P;
            ans=ans*res%P;
        }
	}	
	
	if(y>0)
	{	
		if(c[1]<y)
		{
			cout<<"NO\n";
			return ;
		}
		else 
        {
            int res=0;
            for(int i=y,j=0;i<=c[1]&&j<=c[0];i++,j++)
            res=(res+C(c[1],i)%P*C(c[0],j)%P)%P;
            ans=ans*res%P;
        }
	}
	
	int nx=0,ny=0;
	string res;
	for(auto i:s)
	{
		if(x-nx>0&&i=='U') res+=i,nx++;
		else if(x-nx<0&&i=='D') res+=i,nx--;
		else if(y-ny>0&&i=='R') res+=i,ny++;
		else if(y-ny<0&&i=='L') res+=i,ny--;
		if(nx==x&&ny==y) break;
	}
    if(x==0) ans=ans*C(c[2]+c[3],min(c[2],c[3]))%P;
    if(y==0) ans=ans*C(c[0]+c[1],min(c[0],c[1]))%P;
	cout<<"YES "<<res<<" "<<ans<<"\n";
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
