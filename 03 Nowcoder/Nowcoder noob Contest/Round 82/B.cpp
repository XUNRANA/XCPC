#include <bits/stdc++.h>
using namespace std;
#define N 200010
long long te,t,n,x,y,p[N];
double s,s1,s2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        s=0;
        for(int i=1;i<=n;i++) cin>>p[i],s+=p[i];
        for(int i=1;i<3;i++) for(int j=i+1;j<=n;j++) 
        if(p[j]>p[i]) swap(p[i],p[j]);
        if(p[1]>=y) s1=y+p[2]*(100-x)*0.01;
        else s1=p[1]+p[2]*(100-x)*0.01;
        if(p[2]>=y) s2=y+p[1]*(100-x)*0.01;
        else s2=p[2]+p[1]*(100-x)*0.01;
        cout<<s-max(s1,s2)<<"\n";
    }
}