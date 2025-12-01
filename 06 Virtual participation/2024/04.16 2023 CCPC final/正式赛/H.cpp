#include <bits/stdc++.h>
using namespace std;
int n,t1,c;
void solve()
{
	cin>>n;
	vector<int>u(2*n,0);
	for(int i=1;i<=2*n;i++)
	{
		cin>>t1;
		t1--;
		u[t1]=1;
	}
	c=0;
	for(int i=0;i<2*n;i++) if(u[i]) c++;
	if(c>n) printf("Kevin\n");
	else printf("Qingyu\n");
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
