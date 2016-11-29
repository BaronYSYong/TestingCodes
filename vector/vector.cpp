/*!
 * @file vector.cpp
 * @brief test vector in C++
 * @date 2013/11/15
 * @author Yong Yoon Seong
 * 
 */
 
#include <iostream>
#include <vector>
using namespace std;

int main (int argv,char** argc)
{
    /// create a vector of int
    vector<int> veciTable(3,0);

    /// get the amount of space actually reserved
    cout<<"capacity:"<< veciTable.capacity() << endl;

    /// show the current size of the vector
    cout<< "size:"<< veciTable.size() << endl;

    /// add another 100 integers to the vector
    for(int i=0; i<92; ++i) veciTable.push_back(i);

    /// get the amount of space actually reserved
    cout<<"capacity:"<< veciTable.capacity() << endl;
    
    /// print out the vector
    for(int j=0; j<veciTable.size(); j++) 
        cout<<veciTable[j]<< " ";
    cout<<endl;

    /// show the current size of the vector
    cout<< "size:"<< veciTable.size() << endl;

    /// increase space from 103 to 105 elements
    veciTable.resize(105);
    
    /// print out the vector
    for(int j=0; j<veciTable.size(); j++) 
        cout<<veciTable[j]<< " ";
    cout<<endl;

    /// get the amount of space actually reserved
    cout<<"capacity:"<< veciTable.capacity() << endl;

    /// show the current size of the vector
    cout<< "size:"<< veciTable.size() << endl;

    /// show the maximum size of the array
    cout<< "max_size:"<< veciTable.max_size() << endl;
    
    /// pop back one value
    veciTable.pop_back();
    
    /// print out the vector
    for(int j=0; j<veciTable.size(); j++) 
        cout<<veciTable[j]<< " ";
    cout<<endl;
    
    /// show the amount of space actually reserved after pop back
    cout<<"capacity:"<< veciTable.capacity() << endl;
    
    /// pop front one value;
    veciTable.push_back(101);    
    
    /// print out the vector
    for(int j=0; j<veciTable.size(); j++) 
        cout<<veciTable[j]<< " ";
    cout<<endl;
    
    /// show the amount of space actually reserved after pop front
    cout<<"capacity:"<< veciTable.capacity() << endl;
    
    cout<<veciTable.back()<<endl;    

    return 0;
}
