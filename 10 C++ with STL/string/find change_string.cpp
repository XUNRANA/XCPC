#include <iostream>
#include <string>
using namespace std;
void find()
{
	string str1="abcdefde";
	
	int pos=str1.find("de");
	if(pos==-1) cout<<"Î´ÕÒµ½×Ö·û´®"<<endl;
	else cout<<pos<<endl;
	

	pos=str1.rfind("de");
	if(pos==-1) cout<<"Î´ÕÒµ½×Ö·û´®"<<endl;
	else cout<<pos<<endl;
	// rfind ´ÓÓÒÍù×ó²é  
	// find  ´Ó×óÍùÓÒ²é 
}
void change()
{
	string str1="abcdefg";
	str1.replace(1,3,"1111");  //[1,3]Ìæ»»³É"1111" 
	cout<<str1<<endl;
	
} 
int main()
{
	find();
	cout<<endl;
	change();
}
