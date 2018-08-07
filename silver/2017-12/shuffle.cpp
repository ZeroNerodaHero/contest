#include <iostream>
#include <fstream>
#include <map>
int size;
using namespace std;

int iscycle(int ar[], bool visited[], int start){
    int tmpq = start;
    if(start == ar[start]){
         visited[start] = true;
         return 1;
    }
    int tmp[size];
    tmp[0] = start;
    start = ar[start];
    for(int i = 1; i < size; i++){
        tmp[i] = start;
        start = ar[i];
        if(start == tmp[0]){
            tmp[i++] = -1;
            int j = 0;
            for(; tmp[j] != -1; j++){
                visited[tmp[j]] = true;
            }
            std::cout << "start "<< start; 
            std::cout << "\tj is " << j << std::endl; 
            return j;
        }
    }
    return 0;
}

int main(){
    std::ifstream in("shuffle.in");
    std::ofstream out("shuffle.out");
    
    int count = 0;
    in >> size;
    int pattern[size];
    bool visited[size];
    for(int i = 0; i < size; i++){
        visited[i] = false;
    }   
    //memset(visited,false,size);

    for(int i = 0; i < size; i++){
        int pat;
        in >> pat;
        pattern[i] = pat-1;
    }
    
    for(int i = 0; i < size; i++){
        if(!visited[i]) count+= iscycle(pattern,visited,i);
    }
    std::cout << count << std::endl;
    out << count;
    return 0;
}
