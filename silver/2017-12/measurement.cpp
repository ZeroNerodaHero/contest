#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
    std::ifstream in("measurement.in");
    std::ofstream out("measurement.out");

    std::map<int,int> dayid;
    std::map<int,int> idgallons;
    std::map<int,int> curgallons;
    
    std::map<int,int> daypts;
    

    int size, gallon;
    in >> size >> gallon;
    for(int i = 0; i < size; i++){
        int day;
        in >> day;
        in >> dayid[day];
        curgallons[dayid[day] = gallon;
        in >> idgallons[daychange[day]];
    }

    daypts[0] = gallon;
    for(std::map<int,int>::iterator a = daychange.begin()+1; a != daychange.end(); a++){
        if(idgallons[a->first] < 0){
            if(){
                
            }        
        }
        if(idgallons[a->first] > 0}{

        }       
    }
}
