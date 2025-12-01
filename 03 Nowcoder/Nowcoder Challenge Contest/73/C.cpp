#include<iostream>
using namespace std;
typedef long long ll;
#define M 998244353
int i,n,a,b;
ll f1,f2,f3,f4;
int main()
{
	cin>>n>>a>>b>>n;
	for(i=1;i<=n;i++)
    {
        f1=a*i+b;
        f2+=f1;
        f3+=f2;
        f4+=f3;
		if(!(i%15)||i==n)
        {
            f2%=M;
            f3%=M;
            f4%=M;
        }
	}
	cout<<f1%M<<' '<<f2<<' '<<f3<<' '<<f4;
}