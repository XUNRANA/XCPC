#include <bits/stdc++.h>
using namespace std;
double a[110],d[110];
int n,b,c;
double s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    while(1)
    {
    	cin>>b>>c;
    	if(b==0) break;
    	d[b]+=c;
    	s+=a[b]*c;
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<"\n";
	printf("%.2f",s);
}
