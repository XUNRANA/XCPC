#include <bits/stdc++.h>
using namespace std;
#define N 200010
long long te,t,n,x,y,k,p[2*N],a,b;
double s,s1,p1[2*N];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>x>>y;
        s=s1=0;
        for(int i=1;i<=n;i++) cin>>p[i],s+=p[i];
        for(int i=n+1;i<=2*n;i++) p[i]=0;
        n*=2;
        sort(p+1,p+1+n,[&](int x_,int y_){return x_>y_;});
        for(int i=1;i<=a+b;i++) p1[i]=p[i]*(100-x)*0.01-min(p[i],y),s1+=min(p[i],y);
        sort(p1+1,p1+1+a+b,[&](double x_,double y_){return x_>y_;});
        for(int i=1;i<=a;i++) s1+=p1[i];
        printf("%.12f\n",s-s1);
    }
}