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

    
    string Rev(string s){
	string res = "";
	int len = s.size();
    
	int prev = 0;
	int cnt = 0;
	for (int i = 0; i <=len; i++){
		if (s[i] == ' ' || i == len){
			
			int track = i;
			for (int j = track-1; j >= prev; j--){
				res += s[j];
			}
			prev = track;
			res += ' ';
		}
		
	}
	
	return res;
}
    

}
