#include<bits/stdc++.h>
using namespace std;
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve()
{
	int n=1;
	int cnt=0;
	vector<int>a;
	while(cnt<2024)
	{
		if(__gcd(n,2024)==1) 
		{
			a.push_back(n);
			cnt++;
		}
		n++;
	}
//	cout<<n<<"\n";
//	for(int i=0;i<5;i++) cout<<a[i]<<"\n";
	cout<<a.back()<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
