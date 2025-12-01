#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P1 1331
#define P 998244353
#define N 1000010
int hx[N],hy[N],p[N],hb[N],ha[N];
int getx(int l,int r)
{
	return (hx[r]-hx[l-1]*p[r-l+1]%P+P)%P;
}
int gety(int l,int r)
{
	return (hy[r]-hy[l-1]*p[r-l+1]%P+P)%P;
}
int getb(int l,int r)
{
	return (hb[r]-hb[l-1]*p[r-l+1]%P+P)%P;
}
int geta(int l,int r)
{
	return (ha[r]-ha[l-1]*p[r-l+1]%P+P)%P;
}
void solve()
{
    string a,b;
    cin>>a>>b;
    int x,y;
    cin>>x>>y;
    
	string ax;
    for(int i=x-1;i>=0;i--) ax+=a[i];
    for(int i=a.size()-1;i>=x;i--) ax+=a[i];
//    cout<<ax<<"\n";
    
    string ay;
    for(int i=y-1;i>=0;i--) ay+=a[i];
    for(int i=a.size()-1;i>=y;i--) ay+=a[i];
//    cout<<ay<<"\n";

    int n=ax.size();
    ax=" "+ax+ax;
    ay=" "+ay+ay;
    b=" "+b+b;
    a=" "+a+a;
    
//    cout<<a<<"\n";
//    cout<<b<<"\n";
//    cout<<ax<<"\n";
//    cout<<ay<<"\n";
    
    int z=__gcd(x,y);
    hx[0]=hy[0]=p[0]=hb[0]=ha[0]=1;
	for(int i=1;i<=2*n;i++)
    {
    	hx[i]=(hx[i-1]*P1%P+ax[i]-'a')%P;
    	hy[i]=(hy[i-1]*P1%P+ay[i]-'a')%P;
    	hb[i]=(hb[i-1]*P1%P+b[i]-'a')%P;
    	ha[i]=(ha[i-1]*P1%P+a[i]-'a')%P;
    	p[i]=p[i-1]*P1%P;
	}
	int f=0;
    for(int i=1;i<=n;i+=z)
    {
//    	cout<<i<<" "<<i+n-1<<"\n";
//    	if(getx(i,i+n-1)==getb(1,n)) f=1;
//    	if(gety(i,i+n-1)==getb(1,n)) f=1;
    	if(geta(i,i+n-1)==getb(1,n)) f=1;
	}
	
	if(f) cout<<"yes\n";
	else cout<<"no\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
 	cin>>T;
	while(T--) solve();
}
