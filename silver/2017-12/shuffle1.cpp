#include <iostream>
#include <fstream>
int size;
using namespace std;

int shuffle(int ar[],bool isin[],int size){
    int count = 0;
    bool tmp[size];
    for(int i = 0; i < size; i++){
        tmp[i] = false;
    }
    
    for(int i = 0; i < size; i++){
        if(isin[i]){
            tmp[ar[i]] = true;
        }
    }
    for(int i = 0; i < size; i++){
        if(tmp[i] == true) count++;
    }

    for(int i = 0; i < size; i++){
        isin[i] = tmp[i];
    }
    
    return count;
}

int main(){
    std::ifstream in("shuffle.in");
    std::ofstream out("shuffle.out");
    
    in >> size;
    int count = size;
    int pattern[size];
    bool isin[size];
    for(int i = 0; i < size; i++){
        isin[i] = true;;
    }   

    for(int i = 0; i < size; i++){
        int pat;
        in >> pat;
        pattern[i] = pat-1;
    }
    for(int i = 0; i < size+1; i++){
        int tmp = shuffle(pattern,isin,size);
        if(count == tmp){
            break;
        }       
        count = tmp;
    } 
    
    std::cout << count << std::endl;
    out << count;
    return 0;
}
