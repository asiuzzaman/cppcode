#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="Bangladesh is a beautiful country";
    int prev=0;
    int len=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]==' ' or (i==len-1) ) {
            int track=i;

            for(int j=track;j>=prev;j--){
                cout<<s[j];
            }
            prev=track;

        }
    }

    
    
    
    /// hsedalgnaB si a lufituaeb yrtnuoc


}