#include <bits/stdc++.h>
using namespace std;
int n,c0,j,a[100010],b,c[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    c0=0;
    j=1;
    for(int i=1;i<=n;i++) 
    if(a[i]==0) c0++;
    else 
    {
        b=a[i];
        for(int k=n;k>=i+2;k--) c[j++]=a[k];
        while(c0--) c[j++]=0;
        c[j++]=a[i+1];
        break;
    }
    
    //a[i+1] 0 a[i+2]-a[n]
    int p=0;
    for(int i=1;i<j;i++)
    {
        a[i]=(c[i]*b+p)%10;
        p=(c[i]*b+p)/10;
    }
    if(p) cout<<p;
    for(int i=j-1;i>=1;i--) cout<<a[i];
    cout<<"\n";
}


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int T=1;
    cin>>T;
    while(T--) solve();
}
