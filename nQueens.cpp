#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>&matrix){
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void print(vector<int>&nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

bool check(vector<vector<int>>&matrix,vector<bool>&d1,vector<bool>&d2,vector<bool>&col,int x,int y,int n){
    if(d1[x + y]){
        return false;
    }
    if(d2[x - y + n - 1]){
        return false;
    }
    if(col[y]){
        return false;
    }
    return true;
}

bool nQueen(vector<vector<int>>&matrix,vector<bool>&d1,vector<bool>&d2,vector<bool>&col,int x,int n){
    if(x >= n){
        return true;
    }
    for(int i = 0;i<n;i++){
        if(check(matrix,d1,d2,col,x,i,n)){
            d1[x + i] = true;
            d2[x - i + n - 1] = true;
            col[i] = true;
            matrix[x][i] = 1;
            if(nQueen(matrix,d1,d2,col,x + 1,n)){
                return true;
            }
            d1[x + i] = false;
            d2[x - i + n - 1] = false;
            col[i] = false;
            matrix[x][i] = 0;
        }
    }
    return false;
}
int main(){
    int n = 8;
    vector<vector<int>>matrix(n,(vector<int>(n,0)));
    vector<bool>d1(2*n,false);
    vector<bool>d2(2*n,false);
    vector<bool>col(n,false);
    if(nQueen(matrix,d1,d2,col,0,n)){
        print(matrix);
    }
    else{
        cout<<"FAILURE"<<endl;
    }
    return 0;
}