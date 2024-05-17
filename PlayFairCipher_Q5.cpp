//Playfair Cipher
#include<iostream>
#include<string>
#include <vector>
using namespace std;
int main()
{
    string s,e,key;
    char keyMatrix[5][5];
    vector<string> myVector;
    cout<<"Enter the plain text : ";
    cin>>s;
    cout<<"Enter the key : ";
    cin>>key;
    //Generating key matrix;
    int x=0;
    int chr=97;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(x<key.length())
            {
               keyMatrix[i][j]=key[x];
               x++;
            }
            else
            {

               while(key.find(char(chr)) != string::npos || char(chr)=='j') 
               {
               	    chr++;
	           }  
               keyMatrix[i][j]=char(chr); 
			   chr++;   
            }
            
        }
    }
    //Storing pair of two characters in vector
    int p=0;
    while(p<s.length())
    {
        if(p<(s.length()-1) && s[p]!=s[p+1])
        {
        	string pair = s.substr(p, 2);
            myVector.push_back(pair);
            p+=2;
        }
        else
        {
        	if(p==s.length()-1)
        	{
        		string pair = s.substr(p, 1) + "z";
	            myVector.push_back(pair);
	            p++;
			}
	        else if(s[p]==s[p+1] && (p+1)==s.length()-1 )
	        {
	        	string pair = s.substr(p, 1) + "x";
	            myVector.push_back(pair);
	            string pr = s.substr(p+1, 1) + "x";
	            myVector.push_back(pr);
	            p+=2;
			}
			else
			{
				string pair = s.substr(p, 1) + "x";
	            myVector.push_back(pair);
	            p++;
			} 
        }
    }
    //Process Of Encryption
    for(int k=0;k<myVector.size();k++)
    {
    	int m,n,y,z;
    	string pair=myVector[k];
    	if(pair[0]=='j')
    	{
    		pair[0]='i';
		}
		if(pair[1]=='j')
		{
			pair[1]='i';
		}
    	for(int i=0;i<5;i++)
    	{
    		for(int j=0;j<5;j++)
    		{
    			if(pair[0]==keyMatrix[i][j])
    			{
    				m=i;
    				n=j;
				}
                else if(pair[1]==keyMatrix[i][j])
                {
                	y=i;
                	z=j;
				}
			}
		}
		if(n==z)
		{
			if(m==4)
			{
				m=0;
				y=y+1;
				
			}
			else if(y==4)
			{
				y=0;
				m=m+1;
			}
			else
			{
			   	m=m+1;
			   	y=y+1;
			}
		}
		else if(m==y)
		{
			if(n==4)
			{
				n=0;
				z=z+1;
				
			}
			else if(z==4)
			{
				z=0;
				n=n+1;
			}
			else
			{
			   	n=n+1;
			   	z=z+1;
			}
		}
		else
		{
				int a=n;
				n=z;
				z=a;
		}
		e+=keyMatrix[m][n];
		e+=keyMatrix[y][z];
	}
	cout<<"Corresponding cipher text is : "<<e<<endl;
    return 0;   
}
