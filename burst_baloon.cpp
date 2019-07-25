#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ans;


int FindRight(int Arr[],int n,int j,bool isBrust[], bool &Found){
    if(j>=n){
        Found=false;
        return 1;
    }

    for(int i=j+1;i<n;i++){
        if(!isBrust[i]){
            return Arr[i];
        }
    }
    Found=false;
    return 1; // if no ballon found return 1;
}

int FindLeft(int Arr[],int n,int j, bool isBrust[], bool &Found){
    if(j<=0) {
        Found=false;
        return 1;
    }
    for(int i=j-1;i>=0;i--){
        if(!isBrust[i]){
            return Arr[i];
        }
    }
    Found=false;
    return 1;
}

int Calc(int Arr[],int n,int j, bool isBrust[]){
    int points=0;
    bool leftFound=true;
    bool rightFound=true;
    int left=FindLeft(Arr,n,j,isBrust,leftFound);
    int right=FindRight(Arr,n,j,isBrust,rightFound);

    if(!leftFound and !rightFound){
        points+=Arr[j];
    } else {
        points+=left*right;
    }

    return points;
}


int MaxPoints(int Arr[],int n,int currAns, int count,bool isBrust[]){
        
       if(count==n) ans=max(ans,currAns);

        for(int i=0;i<n;i++){
            if(!isBrust[i]){
                isBrust[i]=true;
                MaxPoints(Arr,n,currAns+Calc(Arr,n,i,isBrust),count+1,isBrust);
                isBrust[i]=false;
            }
        }
    
    return ans;

}
 
int main() {
    int n;
    cin>>n;
     ans=0; //Final Ans is this.......
    int Arr[n];
    bool isBurst[n];
    for(int i=0;i<n;i++){
        cin>>Arr[i];
        isBurst[i]=false;
    }

    int res=MaxPoints(Arr,n,0,0,isBurst);

    cout<<res<<endl;
    
}