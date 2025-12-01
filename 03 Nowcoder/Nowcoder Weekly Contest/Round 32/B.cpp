#include <bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3;
char a[4][4];
void solve()
{
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	ans1=(a[1][1]!='d')+(a[1][2]!='f')+(a[2][1]!='f')+(a[1][3]!='s')+(a[3][1]!='s');
	ans2=(a[1][2]!='d')+(a[2][1]!='d')+(a[2][2]!='f')+(a[2][3]!='s')+(a[3][2]!='s');
    ans3=(a[1][3]!='d')+(a[2][3]!='f')+(a[3][1]!='d')+(a[3][2]!='f')+(a[3][3]!='s');
	cout<<min({ans1,ans2,ans3});
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

