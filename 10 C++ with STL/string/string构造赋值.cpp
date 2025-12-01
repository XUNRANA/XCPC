#include <iostream>
#include <string>
using namespace std;
void create_string() //构造string 
{
	string s1="hello world";
	cout<<"str1 = "<<s1<<endl;
	const char *s2="hello world";
	cout<<"str2 = "<<s2<<endl;
	string s3(s2);
	cout<<"str3 = "<<s3<<endl;
	string s4(10,'a');
	cout<<"str4 = "<<s4<<endl;
}
void fuzhi_string() //赋值string
{
	string str1;
	str1="hello world";
	cout<<"str1 = "<<str1<<endl;
	
	string str2;
	str2=str1;
	cout<<"str2 = "<<str2<<endl;
	
	string str3;
	str3='a';
	cout<<"str3 = "<<str3<<endl;
	
	string str4;
	str4.assign("hello c++");
	cout<<"str4 = "<<str4<<endl;
	
	string str5;
	str5.assign("hello c++",5); //赋值前5个字符 
	cout<<"str5 = "<<str5<<endl;
	
	string str6;
	str6.assign(str5);
	cout<<"str6 = "<<str6<<endl;
	
	string str7;
	str7.assign(10,'x');
	cout<<"str7 = "<<str7<<endl; 
	
} 
int main()
{
	create_string();
	cout<<endl;
    fuzhi_string();
    cout<<endl;
}
