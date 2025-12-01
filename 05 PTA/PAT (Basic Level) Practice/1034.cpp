#include <bits/stdc++.h>
using namespace std;
#define int long long

void func(int m,int n)
{
    if(m*n==0)
    {
        printf("%s",n==0? "Inf":"0");
        return ;
    }
    bool flag=((m<0&&n>0)||(m>0&&n<0));
    m=abs(m);
    n=abs(n);
    int z=m/n;
    m%=n;
    int g=__gcd(m,n);
    m/=g;
    n/=g;
    if(flag) printf("(-");
    if(z) printf("%lld",z);
    if(m) 
    {
        if(z) printf(" ");
        printf("%lld/%lld",m,n);
    }
    if(flag) printf(")");

}
void solve()
{
    int a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    func(a,b);printf(" + ");func(c,d);printf(" = ");func(a*d+b*c,b*d);printf("\n");
    func(a,b);printf(" - ");func(c,d);printf(" = ");func(a*d-b*c,b*d);printf("\n");
    func(a,b);printf(" * ");func(c,d);printf(" = ");func(a*c,b*d);printf("\n");
    func(a,b);printf(" / ");func(c,d);printf(" = ");func(a*d,b*c);printf("\n");
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

