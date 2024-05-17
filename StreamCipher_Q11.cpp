//Stream Cipher
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,key,e,p;
    cout<<"----------------------Stream Cipher--------------------------"<<endl;
    cout<<"Enter the plain text : ";
    cin>>s;
    cout<<"Enter the key : ";
    cin>>key;
    e=p="";
    //Encrypting message
    for(int i=0;i<s.length();i++) 
	{
        e+=s[i]^key[i%(key.length())];
    }
    //Decrypting message
    for(int i=0;i<e.length();i++) 
	{
        p+=e[i]^key[i%(key.length())];
    }
    cout<<"Decrypted text is : "<<p<<endl;
    return 0;
}
