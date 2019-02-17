#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#define MN 100001
using namespace std;
std::ifstream fin("sleepy.in");
std::ofstream fout("sleepy.out");

int ar[MN],br[MN];
int sar[MN];
int N, size = 1;


void insert(int v){
    v++;
    while(v <= N){
        sar[v]++;
        v += v&(-v);
    }
}

int query(int v){
    v++;
    int sum = 0;
    while(v > 0){
        sum += sar[v];
        v -= v&(-v);
    }
    return sum;      
}

bool cmp(int a, int b){
    return ar[a] < ar[b];
}

int main(){
    fin >> N;
    for(int i = 1; i <= N; i++){
        fin >> ar[i];
        br[i] = i; 
    }
    sort(br+1,br+N+1,cmp);
    for(int i = 1; i <= N; i++){
        ar[br[i]] = i;
    }
    /*
    for(int i = 1; i <= N; i++){
        cout << ar[i] << ' ';
    }
    cout << endl;
    */
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
