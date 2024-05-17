//Hill Cipher
//Note: Enter only capital letters
#include<iostream>
using namespace std;
int main()
{
    cout<<"-----------------------------Hill Cipher-------------------------------"<<endl;
    string msg,key,cipher;
    int k;
    cout<<"Enter the  plain text : ";
    cin>>msg;
    cout<<"Enter the size of key matrix : ";
    cin>>k;
    cout<<"Enter the key : ";
    cin>>key; 
    int key_matrix[k][k];
    int msg_matrix[k][1];
    int cipher_matrix[k][1];
    //Generating Key Matrix
    int p=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            key_matrix[i][j]=int(key[p])%65;
            p++;
        }
    }
    int blocks=msg.length()/k;
    int q=0;
    cipher="";
    for(int r=0;r<blocks;r++)
    {
        for(int i=0;i<k;i++)
        {
            msg_matrix[i][0]=int(msg[q])%65;
            q++;
        }
        //Matrix multiplication
        for(int i=0;i<k;i++)
        {
            cipher_matrix[i][0]=0;
            for(int j=0;j<k;j++)    
            {    
                cipher_matrix[i][0]+=key_matrix[i][j]*msg_matrix[j][0];    
            }
            cipher_matrix[i][0]=cipher_matrix[i][0]%26;
        }
        for(int i=0;i<k;i++)
        {
            cipher=cipher+char(cipher_matrix[i][0]+65);
        }
    }
    cout<<"Cipher Text is : "<<cipher<<endl;
    return 0;
}
//m=GFG
//k=HILLMAGIC
