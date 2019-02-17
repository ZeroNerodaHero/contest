#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#define MN 100001
using namespace std;
std::ifstream fin("sleepy.in");
std::ofstream fout("sleepy.out");

int ar[MN];
int sar[524288];
int N, size = 1;


void insert(int s, int e, int i,int v){
    if(s <= v && v <= e){
        sar[i]++;
        if(s == e){
            return;
        }
        int mid = (s+e)/2;
        if(v <= mid) insert(s,mid,2*i+1,v);
        else insert(mid+1,e,2*i+2,v);
    } 
}

void insert(int v){
    insert(0,N,0,v);            
}

int query(int s, int e, int i, int v){
    if(e <= v){
        return sar[i];   
    }
    if(s > v) return 0;
    int mid = (s+e)/2;
    return query(s,mid,2*i+1,v) + query(mid+1,e,2*i+2,v);
}

int query(int v){
    return query(0,N,0,v);      
}

int main(){
    fin >> N;
    for(int i = 1; i <= N; i++){
        fin >> ar[i];
    }
    int k = N;
    do{
        insert(ar[k--]);
    } while(k > 0 && ar[k] < ar[k+1]);
    fout << k << endl;
    for(int i = 1; i <= k; i++){
        int dist = query(ar[i]) + k - i;
        fout << dist;
        if(i != k) fout << ' ';
        insert(ar[i]);
    }
    fout << endl;
}
