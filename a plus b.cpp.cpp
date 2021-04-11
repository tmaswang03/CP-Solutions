#include <iostream>
#include <algorithm>
#include<string>
#include <string.h>
using namespace std;

string subtraction(string str1, string str2){

    string str = "";
    int length1 = str1.length();
    int length2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<length2; i++)
    {
        int sub = (str1[i]-int('0'))-(str2[i]-int('0'))-carry;
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        str+=char(sub + int('0'));
    }
    for (int i=length2; i<length1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        if (sub < 0){
            sub+=10;
            carry+= 1;
        }
        else{
            carry = 0;
        }
        str+=char(sub + int('0'));
    }
    reverse(str.begin(), str.end());
    if(str[0]=='0'){
        str.erase(0,1);
    }
    return str;
}


string addition(string str1, string str2){
  reverse(str1.begin(),str1.end());
  reverse(str2.begin(),str2.end());
  string end="0";
  int length = max(str1.length(),str2.length());
  for(int i = 0; i<length ; ++i){
    int st1, st2, carried;
    if(i<str1.length())
      st1=int(str1[i])-int('0');
    else
      st1=0;
    if(i<str2.length())
      st2=int(str2[i])-int('0');
    else
      st2=0;
    carried=int(end[i])-int('0');
    int carry = 0; int result = 0;
    result=st1+st2+carried;
    if(result>=10){
      carry+=result/10;
      result=result%10;
    }
    char resultstr;
    string carrystr;
    carrystr=to_string(carry);
    resultstr=char(result+int('0'));
    end[i]=resultstr;
    end+=carrystr;
  }
  reverse(end.begin(), end.end());
  if(end[0]=='0'){
    end.erase(0,1);
  }
  return end;
}

int main() {
 int N; cin>>N;
 for(int i = 0 ; i < N; i++){
   string str1, str2;
   cin>>str1>>str2;
   if(str1[0]=='-'&&str2[0]=='-'){
    cout<<"-"<<"";
    str1.erase(0,1);
    str2.erase(0,1);
    cout<<addition(str1,str2)<<endl;
   }
   else if (str1[0]=='-'){
    str1.erase(0,1);
    if(str1.length()>str2.length()){
        cout<<"-"<<"";
        cout<<subtraction(str1,str2)<<endl;
    }
    else if(str2.length()>str1.length()){
        cout<<subtraction(str2,str1)<<endl;
    }
    else if (str1==str2){
        cout<<0<<endl;
    }
    else{
        bool onebigger=false;
        bool twobigger=false;
        for(int i = 0; i < str1.length(); i++){
            if(str1[i]>str2[i]){
                onebigger=true;
                break;
            }
            else if (str2[i]>str1[i]){
                 twobigger=true;
                 break;
            }
        }
        if(onebigger==true){
            cout<<"-"<<"";
            cout<<subtraction(str1,str2)<<endl;
        }
        else{
            cout<<subtraction(str2,str1)<<endl;
        }
    }
   }
    else if (str2[0]=='-'){
    str2.erase(0,1);
    if(str2.length()>str1.length()){
        cout<<"-"<<"";
        cout<<subtraction(str2,str1)<<endl;
    }
    else if(str1.length()>str2.length()){
        cout<<subtraction(str1,str2)<<endl;
    }
    else if (str1==str2){
        cout<<0<<endl;
    }
    else{
        bool onebigger=false;
        bool twobigger=false;
        for(int i = 0; i < str1.length(); i++){
            if(str1[i]>str2[i]){
                onebigger=true;
                break;
            }
            else if (str2[i]>str1[i]){
                 twobigger=true;
                 break;
            }
        }
        if(twobigger==true){
            cout<<"-"<<"";
            cout<<subtraction(str2,str1)<<endl;
        }
        else{
            cout<<subtraction(str1,str2)<<endl;
        }
    }
   }
   else{
    cout<<addition(str1,str2)<<endl;
   }
 }
  return 0;
}
