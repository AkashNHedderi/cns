#include<iostream>
#include<string.h>
using namespace std;
char msg[100],emsg[100];
int key;
void encrypt(char msg[],int key){
	int mlen=strlen(msg);
	int i,j,k=-1,k1=0,row=0,col=0;
	char rail[key][mlen];
	for(i=0;i<key;i++)
		for(j=0;j<mlen;j++)
			rail[i][j]='\n';
	for(i=0;i<mlen;i++){
		rail[row][col++]=msg[i];
		if(row==0||row==key-1)
			k=k*(-1);
			row = row+k;
			}
	cout<<"\nEncrypted Message:";
	for(i=0;i<key;i++)
		for(j=0;j<mlen;j++)
			if(rail[i][j]!='\n'){
				cout<<rail[i][j];
				emsg[k1++]=rail[i][j];
				}		
}					
void decrypt(char emsg[],int key){
	int mlen=strlen(emsg);
	int i,j,k=-1,row=0,col=0,m=0;
	char rail1[key][mlen];
	for(i=0;i<key;i++)
		for(j=0;j<mlen;j++)
			rail1[i][j]='\n';
	for(i=0;i<mlen;i++){
		rail1[row][col++]='*';		
		if(row==0||row==key-1)
			k=k*(-1);
		row=row+k;
		}	
	for(i=0;i<key;i++)
	for(j=0;j<mlen;j++)
	if(rail1[i][j]=='*')
		rail1[i][j]=emsg[m++];
	row=col=0;
	k=-1;
	cout<<"\nDecrypted Message:";
	for(i=0;i<mlen;i++){
		cout<<rail1[row][col++];
		if(row==0||row==key-1)
			k=k*(-1);
		row=row+k;
		}
}
int main(){
	cout<<"Enter the plain text\n";
	cin>>msg;
	cout<<"\nEnter the depth: ";
	cin>>key;
	encrypt(msg,key);
	decrypt(emsg,key);
	return 0;
	}