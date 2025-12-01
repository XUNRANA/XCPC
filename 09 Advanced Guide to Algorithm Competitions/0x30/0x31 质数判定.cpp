#include <bits/stdc++.h>
using namespace std;
int is_1(int x)//质数的判定 78498 7.957
{
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
int is_2(int x)//78498  7.634
{
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	if(x%6!=1&&x%6!=5) return 0;
	for(int i=5;i<=sqrt(x);i+=6) if(x%i==0||x%(i+2)==0) return 0;
	return 1;
} 
int main()
{
	int cnt=0;
	for(int i=0;i<1000000;i++)
	if(is_1(i)) 
	{
		cnt++;
		cout<<i<<endl;
	}
	cout<<endl<<endl;
	cout<<cnt;
}
