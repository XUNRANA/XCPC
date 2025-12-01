#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n%4==0||n%4==1) cout<<"Fluttershy\n";
	else cout<<"Pinkie Pie\n";
}
int main()
{
	int T=1;
	cin>>T;
	while(T--) solve();
}
