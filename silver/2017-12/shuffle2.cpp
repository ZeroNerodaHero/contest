#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

int N;
int a[100001], b[100001];

int main(){
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    
    in >> N;

    for(int i = 1; i <= N; i++){
        in >> a[i];
        b[a[i]]++;
    }   
    int count = N;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(b[i] == 0){
            q.push(i);
            count--;
        }
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();

        b[a[t]]--;
        if(b[a[t]] == 0){
            count--;
            q.push(a[t]);
        }
    }

    cout << count << endl;
    out << count << endl;
    out.close();
    in.close();
    return 0;
}
