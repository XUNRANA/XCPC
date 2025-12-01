#include <bits/stdc++.h>
using namespace std;
int a[30],x;
void solve()
{
	for(int i=1;i<=29;i++) cin>>a[i];
	cin>>x;
	int f=0;
	for(int i=1;i<=29;i++)
	{
		if(x>a[i])
		{
			if(i<=3) cout<<"1";
			else if(i<=9) cout<<"2";
			else if(i<=18) cout<<"3";
			else cout<<"4";
			f=1;
			break;
		}
	}
	if(!f) cout<<"4";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

