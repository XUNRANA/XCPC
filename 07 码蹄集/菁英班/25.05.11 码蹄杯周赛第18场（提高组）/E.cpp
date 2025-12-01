#include <bits/stdc++.h>
using namespace std;
#define int long long
string s,t;
void init()
{
	t+="$";
	t+="#";	
	for(auto i:s)
	{
		t+=i;
		t+="#";
	}
	t+="^";
}
int p[22000010];
void manacher()
{
	init();
	int n=t.size();
	int mr=0,mid;
	for(int i=1;i<n;i++)
	{
		if(i<mr) p[i]=min(p[mid*2-i],mr-i);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]]) p[i]++;
		if(i+p[i]>mr) mr=i+p[i],mid=i;
	}
}
int p1[300010];
int p2[300010];
void solve()
{
	int res=0;
	cin>>s;
    int n=s.size();
	manacher();
	for(int i=0;i<t.size();i++) 
    {
        if(i&1)
        {
            int x=p[i]-1;
            p2[1]++;
            p2[x/2+1]--;
        }
        else
        {
            int x=p[i];
            p1[1]++;
            p1[x/2+1]--;
        }
    }
    for(int i=1;i<=n;i++) p1[i]+=p1[i-1];
    for(int i=1;i<=n;i++) p2[i]+=p2[i-1];
    for(int i=1;i<=n/2;i++)
    {
        cout<<p1[i]<<"\n";
        cout<<p2[i]<<"\n";
    }
    if(n&1) cout<<p1[(n+1)/2]<<"\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}