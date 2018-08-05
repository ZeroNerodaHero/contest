#include <iostream>
#include <fstream>
#include <algorithm>

int search(int ar[], int num, int size){
    for(int i = 0; i < size; i++){
        if(num == ar[i]) return i;
    }
    return 0;
}

int main(){
    std::ifstream in("shuffle.in");
    std::ofstream out("shuffle.out");

    int size; 
    in >> size;

    int pattern[size],before[size], current[size];
    for(int i = 0; i < size; i++){
        in >> pattern[i];
        pattern[i]--;
        current[i] = i;
        before[i] = i;
    }
    int ids[size]; 
    for(int i = 0; i < size; i++){
        in >> ids[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < size; j++){
            before[search(pattern,j,size)] = current[j]; 
        }
        for(int a = 0; a < size; a++){
            current[a] = before[a];
        }
    }
    
    for(int i = 0; i < size; i++){
        out << ids[current[i]] << '\n';
    }
    return 0;
}
