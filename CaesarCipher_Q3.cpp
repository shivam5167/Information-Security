//Caesar Cipher
#include<iostream>
using namespace std;
int main()
{
    string s,e;
    int k;
    cout<<"----------------------Caesar Cipher--------------------------"<<endl;
    cout<<"Enter the plain text : ";
    cin>>s;
    cout<<"Enter the key : ";
    cin>>k;
    e="";
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
        {
            e+=char(((int(s[i])-65+k)%26)+65);
        }
        else
        {
            e+=char(((int(s[i])-97+k)%26)+97);
        }
    }
    cout<<"Encrypted text is : "<<e<<endl;
    return 0;
}
