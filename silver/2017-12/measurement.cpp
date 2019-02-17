#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct record{
    int day, id, change;
    bool operator < (const record &o) const{
        return day < o.day;
    }
};

void print(std::vector<record> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i].day << ' ' << v[i].id<< ' '<< v[i].change << '\n';
    } 
}

int main(){
    std::ifstream in("measurement.in");
    std::ofstream out("measurement.out");

    std::map<int,int> galcount;
    std::map<int,int> idgallons;

    int size, gallon;
    in >> size >> gallon;
    std::vector<record> all(size);

    for(int i = 0; i < size; i++){
        in >> all[i].day >> all[i].id >> all[i].change;
    }
    std::sort(all.begin(), all.end());

//print(all);

    int change = 0;
    galcount[0] = size+2;
    for(int i = 0; i < size; i++){
        std::map<int,int>::reverse_iterator rit = galcount.rbegin();
        int id = all[i].id; 

        bool del;        
        bool wastop = (idgallons[id]== rit->first);
        if(galcount[idgallons[id]] == 1){
            galcount.erase(idgallons[id]);
            del = true;
        } else{
            galcount[idgallons[id]]--;
            del = false;
        }

        idgallons[id] += all[i].change;
        galcount[idgallons[id]]++;
        rit = galcount.rbegin(); 
        bool istop = (idgallons[id] == rit->first);

#if 1
        if(istop){
          if(!wastop || !del || (galcount[idgallons[id]] > 1))
                change++;    
        } else{
            if(wastop) change++;
        }
#else
        if(wastop) {
            if(istop) {
                if(!del || galcount[idgallons[id]] > 1) change++;
            } else {
                change++;
            }
        } else {
            if (istop) change++;
        }
#endif
    }
    std::cout << change << std::endl;
    out << change << '\n';
}
