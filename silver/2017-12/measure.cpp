#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int measurements;
int gallons;

int main(){
    std::ifstream in("measurement.in");
    std::ofstream out("measurement.out");
    
    in >> measurements >> gallons;

    std::map<int,int[]> day;

    for(int i = 0; i < change; i++){
        int d,id,gal;
        in >> d >> id >> gal;
        day[d][d] = gal;
    }

}

