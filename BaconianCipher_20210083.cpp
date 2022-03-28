//#include <iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//#include<map>
//#include<string>
//#include<bits/stdc++.h>
//#include<iomanip>
//using namespace std;
//int main() {
//    map<char,string> letters{{'A',"aaaaa"},{'B',"aaaab"},{'C',"aaaba"},{'D',"aaabb"}
//            ,{'E',"aabaa"},{'F',"aabab"},{'G',"aabba"},{'H',"aabbb"},{'I',"abaaa"}
//            ,{'J',"abaab"},{'K',"ababa"},{'L',"ababb"},{'M',"abbaa"},{'N',"abbab"},
//                             {'O',"abbba"},{'P',"abbbb"},{'Q',"baaaa"},{'R',"baaab"},{'S',"baaba"},
//                             {'T',"baabb"},{'U',"babaa"},{'V',"babab"},{'W',"babba"},{'X',"babbb"},
//                             {'Y',"bbaaa"},{'Z',"bbaab"}};
//    int choice;
//    while(choice !=3){
//        cout<<"-If you want to cipher a message enter 1."<<endl<<"-If you want to decipher a message enter 2."<<endl<<"-If you want to exit the program enter 3.";
//        cout<<endl<<"choice :";
//        cin>>choice;
//        string Str,Cipher="",Decipher="",y="",x="";
//        if(choice==1){
//            cout<<"Enter the message you want to cipher :"<<endl;
//            getline(cin>>ws,Str,'\n');
//            for(int i=0;i<Str.length();i++){
//                if(Str[i]==' '){
//                    Str.erase(i,1);
//                    i--;
//                }
//                Str[i]= toupper(Str[i]);
//            }
//            for(char i : Str){
//                Cipher+=letters[toupper(i)];
//                Cipher+=' ';
//            }
//            cout<<Cipher<<endl;}
//        else if(choice==2){
//            cout<<"Enter the message you want to decipher :"<<endl;
//            getline(cin>>ws,Str,'\n');
//            for(int i=0;i<Str.length();i++){
//                if(Str[i]==' '){
//                    Str.erase(i,1);
//                    i--;
//                }}
//            for(int i=0;i<Str.length();i=i+5){
//                for(int j=i;j<5+i;j++){
//                    x+=Str[j];}
//                for(auto element : letters){
//                    if(element.second==x){
//                        Decipher+=element.first;
//                    }
//                }
//                x="";
//            }cout<<Decipher<<endl;}}
//    return 0;
//}