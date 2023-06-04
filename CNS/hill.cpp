#include<iostream>
using namespace std;
int main()
{
    int k[3][3];
    int p[4][3];
    int res[4][3];
    int i,j,n,q;
    string txt="";
    string result_txt="";
    
    cout<<"ENTER PLAIN TEXT(of length 12) :\n";
    cin>>txt;
    n=txt.length();
    
    
    cout<<"ENTER KEY MATRIX :(3*3) :\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>k[i][j];
        }
    }
    int a=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            int num=int(txt[a++]-97);
            p[i][j]=num;
        }
    }
    
    cout<<"PLAIN TEXT MATRIX :\n";
    for( i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<"KEY MATRIX :\n";
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            for(q=0;q<3;q++)
            {
                res[i][j]+=p[i][q]*k[q][j];
            }
        }
    }
    cout<<"\nRESULT MATRIX\n";
    for(i=0;i<4;i++) 
    {
        for(j=0;j<3;j++)
        {
            res[i][j]=res[i][j]%26;
            cout<<res[i][j]<<" ";
            char ch=char(res[i][j]+97);
            result_txt+=ch;
        }
        cout<<endl;
    }
    cout<<"CIPHER TEXT :\n";
    cout<<result_txt;

}