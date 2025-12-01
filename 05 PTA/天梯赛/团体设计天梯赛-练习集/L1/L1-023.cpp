#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	cin>>s;
	vector<int>a(4,0);
	for(auto i:s) 
	if(i=='G'||i=='g') a[0]++;
	else if(i=='P'||i=='p') a[1]++; 
	else if(i=='L'||i=='l') a[2]++; 
	else if(i=='T'||i=='t') a[3]++; 
	while(1)
	{
		int f=0;
		if(a[0]) cout<<"G",f=1,a[0]--;
		if(a[1]) cout<<"P",f=1,a[1]--;
		if(a[2]) cout<<"L",f=1,a[2]--;
		if(a[3]) cout<<"T",f=1,a[3]--;
		if(!f) break;
	}
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

