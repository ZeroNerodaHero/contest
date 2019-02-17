#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#define MN 100001
using namespace std;
std::ifstream fin("sleepy.in");
std::ofstream fout("sleepy.out");

struct node{
    int l, r, v;
    int sum(){
        return l+r+v;
    }
};

int ar[MN];
node sar[262144];
int N, size = 1;


void insert(int s, int e, int i,int v){
    int mid = (s+e)/2;
    if(v == mid){
        sar[i].v++;
    }
    else if(mid > v){
        sar[i].l++;
        insert(s,mid-1,2*i+1,v);
        //sar[i].l=sar[2*i+1].sum();
    }
    else{
        sar[i].r++;
        insert(mid+1,e,2*i+2,v);
    }
}

void insert(int v){
    insert(0,N,0,v);            
}

int query(int s, int e, int i, int v){
    int mid = (s+e)/2;
    if(mid == v) return sar[2*i+1].sum();
    else if(mid < v) return sar[i].l+sar[i].v + query(mid+1,e,2*i+2,v);
    else return query(s,mid-1,2*i+1,v);
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
