#include <iostream>
#include <fstream>
int dp[10000][10000];
int size;

int findmax(){
    int a = 0, b =0;
    for(int i = 1; i < size-1; i++){
        for(int j = i; j < size; j++){
            if(dp[i][j] > dp[a][b]) a = i, b = j;
        }
    }
    return a-1;
}

int sum(int ar[]){
    for(int i = 0; i < size; i++){
        dp[i][i] = ar[i];
    }   
    for(int i = 0; i < size-1; i++){
        dp[i][i+1] = (ar[i]+ar[i+1])/2;
    }

    for(int l = 2; l < size; l++){ 
        for(int i = 0, j = i + l; j < size; i++,j++){
            dp[i][j] = (dp[i][j-1] + ar[j])/(j+1-i);
        }
    }
    return findmax();
}

int main(){
    std::ifstream in("homework.in");
    std::ofstream out("homework.out");

    in >> size;

    int scores[size];

    for(int i = 0; i < size; i++){
        in >> scores[i];
    }
    
    out << sum(scores);   
    return 0;
}

