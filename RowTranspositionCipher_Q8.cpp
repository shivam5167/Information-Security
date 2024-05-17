//Row Transposition Cipher
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    string msg,key;
    cout<<"Enter key : ";
    cin>>key;
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
    cout<<"Cipher text is : ";
    for(int i=0;i<temp;i++)
    {
        for(int j=0;j<n;j++)
        {
        int temporary=key[j]-'0'-1;
        cout<<arr[i][temporary];
        }  
    }
    return 0;
}
