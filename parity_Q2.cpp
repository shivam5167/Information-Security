#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main()
{
    string m;
    int one=0;
    int ch;
    cout<<"Enter the message : ";
    cin>>m;
    //Checking no. of ones
    for(int i=0;i<m.length();i++)
    {
        if(m[i]=='1')
        {
            one++;
        }
    }
    //appending message with parity bit
    if(one%2==0)
    {
        m+="0";
    }
    else
    {
        m+="1";
    }
    cout<<"Enter 1 for noiseless channel"<<endl;
	cout<<"Enter 2 for noisy channel"<<endl;
	cin>>ch;
    cout<<"---------------------------At Senders End--------------------------------"<<endl;
	cout<<"Message after appending with parity bit :";
	cout<<m<<endl;
	cout<<"---------------------------At Receivers End--------------------------------"<<endl;
	switch(ch)
    {
        case 1:
            {
                cout<<"Received message is : "<<m<<endl;
                cout<<"Receiver received correct data"<<endl;
                break;
            }
        case 2:
            {
                srand(time(0));
	            int s=rand()%(m.length());
	            if(m[s]=='0')
	            {
		           m[s]='1';
	            }
	            else
	            {
		           m[s]='0';
	            }
	            cout<<"Received message is: "<<m<<endl;
                cout<<"Receiver received incorrect data"<<endl;
                break;
            }
        default:
            {
                cout<<"Invalid choice"<<endl;
            }
    }
    cout<<"---------------------------End--------------------------------"<<endl;
	return 0;
}
