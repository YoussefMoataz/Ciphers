//
//#include <iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//#include<bits/stdc++.h>
//#include<iomanip>
//using namespace std;
//int main() {
//    int choice,m=0;
//    string str,decipher="";
//    cout<<"-If you want to cipher a message press 1"<<endl<<"-If you want to decipher a message press 2"<<endl<<"-If you want to exit the program press 3"<<endl;
//    cout<<"choice :";
//    cin>>choice;
//    while(choice!=3){
//        if(m!=0){
//        cout<<"-If you want to cipher a message press 1"<<endl<<"-If you want to decipher a message press 2"<<endl<<"-If you want to exist the program press 3"<<endl;
//        cout<<"choice :";
//        cin>>choice;}
//    if(choice==1){
//    cout<<"Please enter the sentence you want to cipher :"<<endl;
//    getline(cin>>ws,str,'\n');
//    for(int i=0;i<str.length();i++){
//        if(str[i]==32){
//          str=str.erase(i,1);
//        }
//    }
//    string arr[3][str.length()];
//    for(int j=0;j<3;j++){
//        for(int i=0;i<str.length();i++){
//            arr[j][i]='.';
//        }
//    }for(int i=0;i<str.length();i=i+4){
//        arr[0][i]=str[i];
//    }
//    for(int j=1;j<str.length();j=j+2){
//        arr[1][j]=str[j];
//    }
//    for(int i=2;i<str.length();i=i+4){
//        arr[2][i]=str[i];
//    }
//    for(int j=0;j<3;j++){
//        for(int i=0;i<str.length();i++){
//            if(arr[j][i]!="."){
//                cout<<arr[j][i];
//            }
//        }}cout<<endl;}
//      else if(choice==2){
//          cout<<"Please enter the sentence you want to decipher :"<<endl;
//          cin>>str;
//          string arr[3][str.length()];
//          for(int j=0;j<3;j++){
//              for(int i=0;i<str.length();i++){
//                  arr[j][i]='.';
//              }
//          }int x=0;
//          for(int i=0;i<str.length();i=i+4){
//              arr[0][i]=str[x];
//              ++x;
//          }int y=str.length()/4;
//          for(int j=1;j<str.length();j=j+2){
//              arr[1][j]=str[y];
//              ++y;
//          }int z=str.length()/2+str.length()/4;
//          for(int i=2;i<str.length();i=i+4){
//              arr[2][i]=str[z];
//              ++z;
//          }
//                  bool increase = true;
//                  int h = 0;
//                  for (int i=0;i<str.length();i++){
//                  decipher += arr[h][i];
//                  if (h == 0){
//                  increase=true;}
//                  else if (h==2){
//                  increase=false;}
//                  if (increase) {h++;}
//                  else{h--;}}
//    cout<<decipher<<endl;}m++;}
//
//    return 0;
//}
