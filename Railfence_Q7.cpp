//Railfence Encryption
#include<iostream>
using namespace std;
int main()
{
    int k,l,i,j,f;
    string s,e;
    e="";
    cout<<"Enter the plain text : ";
    getline(cin,s);
    cout<<"Enter key  : ";
    cin>>k;
    l=s.length();
    char m[k][l];
    for(int i=0;i<k;i++)
    {
    	for(int j=0;j<l;j++)
        {
            m[i][j]='?';
        }
    }
    i=0;
    j=0;
    f=0;
    for(int p=0;p<l;p++)
    {
        m[i][j]=char(s[p]);
        if(f==0)
        {
            i=i+1;
            if(i==k-1)
			{
            	f=1;
            }
        }
        else
        {
            i=i-1;
            if(i==0)
			{
            	f=0;
            }
        }
        j++;
    }
    for(int i=0;i<k;i++)
    {
    	for(int j=0;j<l;j++)
        {
            if(m[i][j]!='?')
            {
            	e+=m[i][j];
            }   
        }
    }
    cout<<"------------------------Railfence Encryption-------------------------------"<<endl;
    cout<<"Original text is :"<<s<<endl;

    cout<<"Corresponding encrypted text is :"<<e<<endl;
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
