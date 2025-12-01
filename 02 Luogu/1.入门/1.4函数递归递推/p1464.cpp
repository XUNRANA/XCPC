#include <bits/stdc++.h>
using namespace std;
long long ans[25][25][25];
long long f(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return f(20,20,20);
	if(ans[a][b][c]) return ans[a][b][c];
	if(a<b&&b<c) ans[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
	else ans[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
	return ans[a][b][c];
}
int main()
{
	long long a,b,c;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==b&&b==c&&a==-1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,f(a,b,c));
	}
}
/*
#include <bits/stdc++.h>
using namespace std;
long long ans[25][25][25];
long long w(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0) return 1ll;
	else if(ans[a][b][c]) return ans[a][b][c];
	else if(a>20||b>20||c>20) ans[a][b][c]=w(20,20,20);
	else if(a<b&&b<c) ans[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return ans[a][b][c];
}
int main()
{
	long long a,b,c;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==-1&&a==b&&a==c) break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
		if(a>20) a=21;
		if(b>20) b=21;
		if(c>20) c=21;
		cout<<w(a,b,c)<<"\n";
	}
}
*/
