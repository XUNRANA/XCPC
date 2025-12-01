#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
	int n;
	cin>>n;
	int i[3] {1,2,3};
	while(1)
	{
		cout<<"? "<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
		int p;
		cin>>p;
		if(!p) break;
		int x=rng()%3;
		i[x]=p;
	}
	cout<<"! "<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
}
int main() 
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

