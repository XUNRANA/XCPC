#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
int t[300010];
vector<int>b;
int j;
void init()
{
    j=0;
    t[j++]=-2e9;
	t[j++]=1e9;	
	for(auto i:b)
	{
		t[j++]=i;
		t[j++]=1e9;
	}
	t[j++]=-3e9;
}
int p[22000010];
void manacher()
{
	init();
	int n=j;
	int mr=0,mid;
	for(int i=1;i<n;i++)
	{
		if(i<mr) p[i]=min(p[mid*2-i],mr-i);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]]) p[i]++;
		if(i+p[i]>mr) mr=i+p[i],mid=i;
	}
}





void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    b.clear();
    for(int i=2;i<=n;i++) b.push_back(a[i]-a[i-1]);
    manacher();
    int ans=n;
    for(int i=1;i<=2*b.size();i++) ans+=p[i]/2;
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}