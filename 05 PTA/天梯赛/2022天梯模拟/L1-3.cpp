#include<bits/stdc++.h>
using namespace std;

void solve()
{
	double a,b,c;
	cin>>a>>b>>c;
	double k;
	if(b==0) k=2.455;
	else k=1.26;
	

	
	printf("%.2f ",a*k);
	if(c<k*a) printf("T_T");
	else printf("^_^");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}


