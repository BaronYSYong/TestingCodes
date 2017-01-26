#include <stdio.h>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(7);
    a.push_back(9);
    
    //~ printf("a.size = %d\n", a.size());    
    std::cout << a.size() << std::endl;
    
    for(int j=0; j<a.size(); j++) 
        printf("%d\n", a[j]);
}
