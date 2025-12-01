#include <bits/stdc++.h>
using namespace std;
void solve()
{
	double a,b,c,k;
	cin>>a>>b>>c;
	if(b==0) k=2.455;
	else k=1.26;
	printf("%.2f ",a*k);
	if(a*k>c) printf("T_T");
	else printf("^_^");
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

