#include <iostream>
#include <string>
using namespace std;
void compare()
{
	string str1="hello";
	string str2="hello";
	cout<<str1.compare(str2)<<endl;  //ПаµИ         0
	str2="gello";
	cout<<str1.compare(str2)<<endl;  //str1>str2    1
	str2="iello"; 
	cout<<str1.compare(str2)<<endl;  //str1<str2   -1
}
int main()
{
	compare();
}
