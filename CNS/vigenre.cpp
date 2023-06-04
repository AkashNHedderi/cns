#include<iostream>
#include<string>
using namespace std;


string generateKey(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}


string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
       
        char x = (str[i] + key[i]-97-97) %26;

        
        x += 'a';

        cipher_text.push_back(toupper(x));
    }
    return cipher_text;
}


string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        
        char x = (cipher_text[i] - key[i] + 26) %26;

        
        x += 'a';
        orig_text.push_back((x));
    }
    return orig_text;
}


int main()
{
    string str;
    string keyword ;
    cout<<"ENTER PLAIN TEXT :\n";
    cin>>str;
    cout<<"ENTER KEY : \n";
    cin>>keyword;

    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);

    cout << "CIPHER TEXT(AFTER ENCRYPTION) : "
        << cipher_text << "\n";

    cout << "Original/Decrypted Text : "<< str;
    return 0;
}