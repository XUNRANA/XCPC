#include<bits/stdc++.h>
using namespace std;
int t,n,m,p;
int main()
{
    cin>>t;
	while(t--)
	{
		cin>>n>>m>>p;
		if((p==1&&n>m+1)||(n==1)) puts("YangQiShaoNian");
		else puts("XiaoNian");
	}
}