#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Team{
	string tn;
	int ts;
	int tp;
}a[N],b[N];
bool cmp(Team a1,Team a2)
{
	if(a1.ts==a2.ts) return a1.tp<a2.tp;
	return a1.ts>a2.ts;
}
int n,m,r1,r2,c1,c2;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].tn>>a[i].ts>>a[i].tp;
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i].tn>>b[i].ts>>b[i].tp;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	map<string,int>m1,m2;
	for(int i=1;i<=n;i++) 
	{
		m1[a[i].tn]=1;
		m2[b[i].tn]=1;
		if(a[i].tn=="lzr010506") r1=i;
		if(b[i].tn=="lzr010506") r2=i;
	}
	
	for(int i=1;i<r1;i++) if(m2.count(a[i].tn)) c1++;
	for(int i=1;i<r2;i++) if(m1.count(b[i].tn)) c2++;
	cout<<min(r1-c1,r2-c2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
