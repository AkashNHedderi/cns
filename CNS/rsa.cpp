#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,q,n,phi,d,e;
    double pt,c;
    cout<<"ENTER TWO PRIME NUMBERS :\n";
    cin>>p>>q;
    
    n=p*q;
    phi=(p-1)*(q-1);
    
    cout<<"VALUE OF (n) :\n";
    cout<<n<<endl;
    
    cout<<"VALUE OF (phi) :\n";
    cout<<phi<<endl;
    
    cout<<"ENTER VALUE OF (e) :\n";
    cin>>e;
    
    int k=1;
    while(1)
    {
        if((1+(k*phi))%e==0)
        {
            d=((1+(k*phi))/e);
            break;
        }
        else
            k++;
    }
    
    cout<<"VALUE OF (d) is :\n";
    cout<<d;
    
    cout<<"\nPUBLIC KEY :"<<endl;
    cout<<"["<<e<<" "<<n<<"]"<<endl;
    
    cout<<"PRIVATE KEY :"<<endl;
    cout<<"["<<d<<" "<<n<<"]"<<endl;
    
    cout<<"ENTER PLAIN TEXT NUMBER :"<<endl;
    cin>>pt;
    
    double temp1=pow(pt,e);
    c=fmod(temp1,n);
    
    cout<<"Cypher Text/Encrypted Text :"<<endl;
    cout<<c;
    
    double x=pow(c,d);
    x=fmod(x,n);
    cout<<"\nPlain Text/Decrypted Text :\n";
    cout<<pt;
   
}