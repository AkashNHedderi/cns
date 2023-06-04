#include<iostream>
using namespace std;

void encrypt(string txt,int s);
void decrypt(string txt,int s);

int main()
{
    string txt;
    int s;
    cout<<"ENTER PLAIN TEXT\n";
    cin>>txt;
    cout<<"ENTER NUMBER OF SHIFT\n";
    cin>>s;
    encrypt(txt,s);
}

void encrypt(string txt,int s)
{
    int n=txt.length();
    string res="";
    for(int i=0;i<n;i++)
    {
        if(isupper(txt[i]))
        {
            res+=char(int(txt[i]+s-65)%26+65);
        }
        else
            res+=char(int(txt[i]+s-97)%26+97);
    }
    cout<<"ENCRYPTED TEXT IS :\n";
    cout<<res;
    decrypt(res,s);
}

void decrypt(string txt,int s)
{
    string res="";
    int n=txt.length();
    int m=26-s;
    for(int i=0;i<n;i++)
    {
        if(isupper(txt[i]))
            res+=char(int(txt[i]-s-65)%m+65);
        else
            res+=char(int(txt[i]-s-97)%m+97);
    }
    cout<<"\nDECRYPTED TEXT IS :\n";
    cout<<res;
}