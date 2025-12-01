#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if((a+b)&1) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}
/*
Alice a coins,Bob b coins
with Alice first,take turns
every round,take turns to move:(exchange wallets or not) and then remove 1 coin  
loser:cannot make a valid move 
*/
/*
显然，每一回合每个人都要减少一个coin,
当最后一个coin是谁remove的谁就赢了 
a+b==odd Alice win
a+b==even Bob win 
*/
