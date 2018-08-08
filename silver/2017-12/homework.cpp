#include <iostream>
#include <fstream>
int dp[10000][10000];
int size;

int main(){
    std::ifstream in("homework.in");
    std::ofstream out("homework.out");

    in >> size;

    int scores[size];

    for(int i = 0; i < size; i++){
        in >> scores[i];
    }
   
    float small = std::min(scores[size-2],scores[size-1]);
    float total = scores[size-2] + scores[size-1];
    float bigavg = (scores[size-2] + scores[size-1])/2;
    int point = size-2;
    std::cout << "avg\t" << bigavg << std::endl;
    std::cout << "total\t" << total<< std::endl;
    for(int i = size-3; i >= 0; i--){
        int range = size - i;
        std::cout << i << "-\t" << (total + scores[i] - small)/range << std::endl;
        if(scores[i] < small) small = scores[i];
        total += scores[i];
        float avg = (total - small)/range;
        if(avg > bigavg){
            std::cout << "changed" << bigavg << "->" <<  avg << std::endl;
            bigavg = avg;
            point = i;
        }
    }

    std::cout << "Answer:\t" << point;
    out << point;
 
    return 0;
}

