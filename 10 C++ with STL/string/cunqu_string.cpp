#include <iostream>
#include <string>
using namespace std;
void cunqu()
{
	string str="hello";
	cout<<str<<endl;
	for(int i=0;i<str.size();i++) cout<<str[i];
	for(int i=0;i<str.length();i++) cout<<str.at(i);
	cout<<endl;
	str.at(1)='a';
	str[0]='a';
	cout<<str<<endl;
}
int main()
{
	cunqu(); 
}
