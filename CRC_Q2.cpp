//guildlines Q2
#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
class CRC
{
	public:
		int n,m;
	    int *Data_Sender,*temp1,*temp2,*divisor,*crc;
    	CRC();
    	~CRC();
	    void append(int arr[]);
	    void divide(int arr1[]);
	    void received();
};
CRC::CRC()
{
	cout<<"Enter the no. of bits of data word :";
	cin>>n;
	Data_Sender=new int[n];
	cout<<"Now Enter the bits of data word one by one :";
	for(int i=0;i<n;i++)
	{
		cin>>Data_Sender[i];
	}
	cout<<"Enter the no. of bits of generator word :";
	cin>>m;
	divisor=new int[m];
	cout<<"Now Enter the bits of generator word one by one :";
	for(int i=0;i<m;i++)
	{
		cin>>divisor[i];
	}
	temp1=new int[n+m-1];
	temp2=new int[n+m-1];
	for(int i=0;i<n;i++)
	{
		temp1[i]=Data_Sender[i];
		temp2[i]=Data_Sender[i];
	}
	cout<<"Data word :";
	for(int i=0;i<n;i++)
	{
		cout<<Data_Sender[i];
	}
	cout<<endl;
	cout<<"Generator word :";
	for(int i=0;i<m;i++)
	{
		cout<<divisor[i];
	}
	cout<<endl;
	crc=new int[m-1];
	for(int i=0;i<m-1;i++)
	{
		crc[i]=0;
    }
}
void CRC::append(int arr[])
{
	int r=0;
	for(int i=n;i<(n+m-1);i++)
	{
		arr[i]=crc[r];
		r++;
	}
	for(int i=0;i<(n+m-1);i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
void CRC::divide(int arr1[])
{
	for(int i=0;i<n;i++)
	{  
	    int k=i; 
		if(arr1[k]>=divisor[0])
		{ 
			for(int j=0,k=i;j<m;j++,k++)
			{
				if(arr1[k]==divisor[j])
			    {
				    arr1[k]=0;
			    }
			    else
			    {
			    	arr1[k]=1;
			    }
		    	
	        }
	    }
	    
	}
	int q=0;
	for(int i=n;i<n+m-1;i++)
	{
		crc[q]=arr1[i];
		q++;
    }
    for(int i=0;i<m-1;i++)
	{
		cout<<crc[i];
    }
    cout<<endl;
}
void CRC::received()
{
	int a=m+n;
	srand(time(0));
	int s=rand()%a;
	if(temp2[s]==0)
	{
		temp2[s]=1;
	}
	else
	{
		temp2[s]=0;
	}
	cout<<"Received data is: ";
	for(int i=0;i<(m+n-1);i++)
	{
		cout<<temp2[i];
	}
	cout<<endl;	
}
CRC::~CRC()
{
	delete Data_Sender;
	delete temp1;
	delete temp2;
	delete divisor;
	delete crc;
}
int main()
{
	int ch;
	int flag=1;
	char choice;
	do
	{
		CRC obj;
		cout<<"Enter 1 for noiseless channel"<<endl;
		cout<<"Enter 2 for noisy channel"<<endl;
		cin>>ch;
		cout<<"---------------------------At Senders End--------------------------------"<<endl;
	    cout<<"Data word after appending with zeroes :";
	    obj.append(obj.temp1);
	    cout<<"CRC bits are :";
	    obj.divide(obj.temp1);
		cout<<"---------------------------Transmitted Data--------------------------------"<<endl;
	    cout<<"Data word after appending with crc bits :";
	    obj.append(obj.temp2);
	    cout<<"---------------------------At Receivers End--------------------------------"<<endl;
		switch(ch)
		{
			case 1:
				{
	                cout<<"Resultant CRC bits are :";
	                obj.divide(obj.temp2);
	                break;
				}
			case 2:
				{
					obj.received();
					cout<<"Resultant CRC bits are : ";
					obj.divide(obj.temp2);
					break;
				}
			default:
				{
					cout<<"Invalid choice"<<endl;
				}
		}
		for(int i=0;i<obj.m-1;i++)
	    {
		   if(obj.crc[i]!=0)
		   {
			  flag=0;
		   }
        }
        if(flag==1)
        {
    	    cout<<"Receiver received correct data"<<endl;
    	    cout<<endl;
	    }
	    else
	    {
		    cout<<"Receiver received incorrect data"<<endl;
		    cout<<endl;
	    }
	    flag=1;
		cout<<"Do you want to continue(y/n) : ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
	getch();
	return 0;
}
