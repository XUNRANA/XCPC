#include <bits/stdc++.h>
using namespace std;
int main()
{
	//lowbit(n) 最低位1及后面所有的0
	int n=60;//111100; 
	cout<<(n&(~n+1))<<endl; 
	cout<<(n&(-n))<<endl;
} 
