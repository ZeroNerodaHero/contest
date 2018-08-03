#include <iostream>
#include <fstream>
using namespace std;
int size(int a[],int b[]){
    if(a[0] > b[2] || a[2] < b[0] || a[1] > b[2] || a[2] < b[1])
        return 0;
    std::cout << min(a[2],b[2]) << ' '<< max(a[0],b[0]) << ' ' <<min(a[3],b[3]) << ' ' << max(a[1],b[1]);
    std::cout << std::endl;
    return (min(a[2],b[2]) - max(a[0],b[0])) * (min(a[3],b[3])- max(a[1],b[1]));
    
}

int main(){
    std::ifstream in("billboard.in");
    std::ofstream out("billboard.out");
    int ar[3][4];
    int sum = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            in >> ar[i][j];
        }
    } 

    sum += (ar[0][2]-ar[0][0]) * (ar[0][3]-ar[0][1]);
    sum += (ar[1][2]-ar[1][0]) * (ar[1][3]-ar[1][1]);

    std::cout << sum << std::endl;
    sum -= size(ar[0],ar[2]);

    std::cout << sum << std::endl;

    sum -= size(ar[1],ar[2]);
    std::cout << sum << std::endl;
    out << sum;
}
