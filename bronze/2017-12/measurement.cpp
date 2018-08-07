#include <iostream>
#include <fstream>
#include <map>
using namespace std;

bool diff(int ar1[], int ar2[]){
    int max1 = std::max(std::max(ar1[0],ar1[1]),ar1[2]);
    int max2 = std::max(std::max(ar2[0],ar2[1]),ar2[2]);
    for(int i = 0; i < 3; i++){
        if(ar1[i] == max1){
            if(ar2[i] != max2) return true;
        }
        else{
            if(ar2[i] == max2) return true;
        }
    }
    return false;
}

int milk[101][3];
int main(){
    std::ifstream in("measurement.in");
    std::ofstream out("measurement.out");
    
    int change = 0, largest = 0; 
    in >> change;

    std::map<std::string,int> names;
    names["Bessie"] = 0;
    names["Elsie"] = 1;
    names["Mildred"] = 2;

    for(int i = 0; i < change; i++){
        int day; std::string cow;
        in >> day >> cow;
        in >> milk[day][names[cow]];
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
