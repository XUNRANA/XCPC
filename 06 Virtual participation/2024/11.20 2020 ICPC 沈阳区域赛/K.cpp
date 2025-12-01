#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node
{
	char op;
	int v;
}a[N];
int t,tn,fn,tp,fp;
double ans,preX;
bool cmp(node a1,node a2)
{
	if(a1.v==a2.v) return a1.op<a2.op;
	return a1.v<a2.v;
} 
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].op>>a[i].v;
		if(a[i].op=='+') fn++;
		else tn++;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>=1;i--)
	{
		if(a[i].op=='+') tp++,fn--;
		else fp++,tn--;
		ans+=1.0*tp/(tp+fn)*(1.0*fp/(tn+fp)-preX);
		preX=1.0*fp/(tn+fp);
	}
	cout<<setprecision(10)<<fixed<<ans<<"\n";

}
/*
 3
 + 2
 - 3
 - 1
 
  6
 + 7
 - 2
 - 5
 + 4
 - 2
 + 6
 
 
  8
 + 34
 + 33
 + 26
 - 34
 - 38
 + 39
 - 7
 - 27
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
