#include <bits/stdc++.h>
using namespace std;
long long n,la,a,c1,c2,sum,ans,l,r;
void solve() 
{
	ans=sum=0;
    cin>>n>>la;
    for(int i=1;i<n;i++)
    {
    	cin>>a;
    	c1=c2=0;
    	l=la,r=a;
    	while(l<r) l<<=1,c1++;
    	while(l>r) r<<=1,c2++;
    	sum+=c2-c1;
    	sum=max(0ll,sum);
    	ans+=sum;
    	la=a;
	}
    cout<<ans<<"\n";
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
	cin>>t;
    while(t--) solve();
}
