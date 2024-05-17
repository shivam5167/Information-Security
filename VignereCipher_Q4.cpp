//Vignere Cipher(Q4)
//Note :- Enter in small letters only
#include<iostream>
using namespace std;
int main()
{
    string s,k,key,e;
    cout<<"----------------------Vignere Cipher--------------------------"<<endl;
    cout<<"Enter the plain text : ";
    cin>>s;
    cout<<"Enter the key : ";
    cin>>k;
    e="";
    key=k;
    if(s.length()>k.length())
    {
    	int index=0;
    	for(int i=0;i<(s.length()-k.length());i++)
        {
    	    if(index==k.length())
    	    {
    	    	index=0;
			}
			key+=k[index];
			index++;
	    }
	}
    for(int i=0;i<s.length();i++)
    {
            e+=char((((int(s[i])-97)%26)+((int(key[i])-97)%26))%26+97);
    }
    cout<<"Encrypted text is : "<<e<<endl;
    return 0;
}
//m=geeksforgeeks
//k=ayush
