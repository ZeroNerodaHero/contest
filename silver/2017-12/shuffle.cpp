#include <iostream>
#include <fstream>
using namespace std;

int N, *a;
bool b[100001], c[100001];
int shuffle(bool b1[], bool c1[]){
    int count = 0;
    for(int i = 1; i <= N; i++){
        c1[i] = false;
    }
    
    for(int i = 1; i <= N; i++){
        if(b1[i]){
            if(!c1[a[i]]){
                count++;
                c1[a[i]] = true;
            }
        }
    }
    return count;
}

int main(){
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    
    in >> N;
    bool *b1 = b;
    bool *c1 = c;
    a = new int[N+1];

    for(int i = 1; i <= N; i++){
        in >> a[i];
        b[i] = true;
    }   

    int prev, count = N;
    do{
        prev = count;
        count = shuffle(b1,c1);
        std::cout << prev << " - " << count << std::endl; 
        swap(b1,c1);
    } while(prev != count);

    cout << count << endl;
    out << count << endl;
    out.close();
    in.close();
    delete[] a;
    return 0;
}
