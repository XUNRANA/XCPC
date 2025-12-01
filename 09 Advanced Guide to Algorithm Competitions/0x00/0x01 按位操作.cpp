#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=5;           //0101
    int b=3;           //0011
	cout<<(a&b);       // &
	cout<<endl<<endl;  //0001  both 1 to 1     ans=1 
	
	int a1=5;           //0101
    int b1=3;           //0011
	cout<<(a1|b1);      // |
	cout<<endl<<endl;   //0111 both 0 to 0     ans=7 
	
	int a2=5;           //0101
    int b3=3;           //0011
	cout<<(a2^b3);      // ^
	cout<<endl<<endl;   //0110  differ to 1    ans=6 
	
	int a3=10;          // 1010
	a=1;                // 0001
	cout<<(a3^a);       // ^
	cout<<endl<<endl;   // 1011 differ to 1  ans=11
	//1^(2*n) == (2*n)+1 
	
	int b4=21;          //10101
	a=1;                // 0001
	cout<<(b4^a);       //  ^
	cout<<endl<<endl;   //10100 differ to 1  ans=20
	//1^(2*n+1) == (2*n+1)-1
}
