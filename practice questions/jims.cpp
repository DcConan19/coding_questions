/* Adam and Eve want to communicate over a secured channel through encrypted messages. Some encryption techniques are available  in which each alphabet in the text or messages is shifted by a number of places down the alphabet.

For example, with a shift of 2, A would be replaced by C, C would become E, and so on.

To pass an encrypted message from one person to another, it is first necessary that both parties have the ‘Key’ for the cipher, so that the sender may encrypt and the receiver may decrypt it.

Key is the number of OFFSET to shift the cipher alphabet. Key can have basic shifts from 1 to 25 positions as there are 26 total alphabets.

As we are designing custom Shift Cipher, in addition to alphabets, we are considering numeric digits from 0 to 9. Digits can also be shifted by key places.

For Example, if a given plain text contains any digit with values 5 and keyy =2, then 5 will be replaced by 7, “-”(minus sign) will remain as it is. Key value less than 0 should result into “INVALID INPUT”

Example 1:

Enter your PlainText: All the best

Enter the Key: 1

The encrypted Text is: Bmm uif Cftu

Write a function encryption(int key, String message) which will accept

plaintext and key as input parameters and returns its cipher text as output. */

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    getline(cin,s);
    int key;
    cin>>key;
    vector<char> arrLower(26);
    vector<char> arrUpper(26);
    vector<char> arrDigit(10);
    char lowerch='a';
    char upperch='A';
    char numch='0';
    for(int i=0;i<26;i++){
        arrLower[i]=lowerch+i;
        // cout<<arrLower[i]<<endl;
    }
    for(int i=0;i<26;i++){
        arrUpper[i]=upperch+i;
    }
    for (int i = 0; i <10; i++)
    {
        arrDigit[i] = numch + i;
    }
    if(key<0){
        cout<<"INVALID INPUT"<<endl;
        return 0;
    }
    // cout<<s<<endl;
    // cout<<s[0]<<endl;
    for(int i=0; i< s.length();i++){
        if(isupper(s[i]) && isalpha(s[i])){
            s[i]=arrUpper[(s[i]-'A' + key)%26];
        }else if ( islower(s[i]) && isalpha(s[i])){
            s[i]=arrLower[(s[i]-'a' + key)%26];
        }else if(isdigit(s[i])){
            s[i]=arrDigit[(s[i]-'0' + key)%10];
        }
    }
    cout<<s<<endl;
    return 0;
}

