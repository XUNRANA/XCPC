#include <iostream>
#include <string>
using namespace std;
void substr()
{
	string str="abcdefg";
	string s=str.substr(1,3);  //Ωÿ»°[1,3] 
	cout<<s<<endl;
}
void get()
{
	string email="xunrana@163.com";
	int pos=email.find("@");
	string user=email.substr(0,pos);
	cout<<user;
}
int main()
{
	substr();
	get();	
}
