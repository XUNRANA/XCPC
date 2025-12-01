#include <bits/stdc++.h>
using namespace std;
int a[100010];
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>f(n+1,0);
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		f[a[i]]=1;
	}
	for(int i=0;i<=n;i++) if(!f[i]) a[n]=i;
	for(int i=0;i<n;i++) cout<<a[(n+1+i-k%(n+1))%(n+1)]<<" ";
	cout<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}


