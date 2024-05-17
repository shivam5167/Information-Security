//Product Cipher Transposition
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    string msg,key,e,cipher;
    int k;
    e="";
    cipher="";
    cout<<"Enter key 1: ";
    cin>>key;
    cout<<"Enter key 2: ";
    cin>>k;
    cout<<"Enter message : ";
    cin>>msg;
    int n=key.length();
    float x=msg.length();
    float no=x/n;
    int temp=ceil(no);
    char arr[temp][n]={};
    for(int i=0;i<temp;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=msg[i*(n)+j];
            if(i*n+j>msg.length())
            {
                arr[i][j]='X';
            }
        }
    }
    for(int i=0;i<temp;i++)
    {
        for(int j=0;j<n;j++)
        {
        int temporary=key[j]-'0'-1;
        e+=arr[i][temporary];
        }  
    }
    for(int i=0;i<e.length();i++)
    {
        if(isupper(e[i]))
        {
            cipher+=char(((int(e[i])-65+k)%26)+65);
        }
        else
        {
            cipher+=char(((int(e[i])-97+k)%26)+97);
        }
    }
    cout<<"Encrypted text is : "<<cipher<<endl;
    return 0;
}
