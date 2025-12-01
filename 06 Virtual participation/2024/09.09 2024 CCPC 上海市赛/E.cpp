#include <bits/stdc++.h>
using namespace std;
int c1,c2,c3,c4,c5,c6;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	for(auto i:s)
	{
		if(i=='s'||i=='S') c1++;
		else if(i=='h'||i=='H') c2++;
		else if(i=='a'||i=='A') c3++;
		else if(i=='n'||i=='N') c4++;
		else if(i=='g'||i=='G') c5++;
		else if(i=='i'||i=='I') c6++;
	}
	cout<<min({c2/2,c3/2,c1,c4,c5,c6});
	//shanghai 
	//s n g i
	//a h
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
