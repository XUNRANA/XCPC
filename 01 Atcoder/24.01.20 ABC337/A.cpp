#include <bits/stdc++.h>
using namespace std;
long long n,x,y,sx,sy;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		sx+=x;
		sy+=y;
	}
	if(sx>sy) cout<<"Takahashi";
	else if(sx<sy) cout<<"Aoki";
	else cout<<"Draw";
	
}
