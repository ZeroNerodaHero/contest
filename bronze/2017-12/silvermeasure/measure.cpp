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
        day[d][id] = gal;
    }

    


    change = 0;
    for(int i = 0; i < 3; i++) milk[0][i] = 7;
    for(int i = 1; i <= 100; i++){
        milk[i][0] += milk[i-1][0];
        milk[i][1] += milk[i-1][1];
        milk[i][2] += milk[i-1][2];
        
        if(diff(milk[i],milk[i-1])){
            change++;
        }
    }
    //if(!diff(milk[99],milk[98])) change--;
    cout << change << '\n';
    out << change << '\n';
}

