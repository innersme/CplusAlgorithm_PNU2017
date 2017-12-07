//
//  k-mer.cpp
//  CplusAlgorithm_PNU2017
//
//  Created by MJMacBook on 2017. 11. 28..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};

map <string, int> mapData ;
map <string, int>::iterator it ;
map <int, string> rtnData;
ifstream inpStream("/Users/innersme/C_study/CplusAlgorithm_PNU2017/sampleData8/1.inp") ;
ofstream outStream("/Users/innersme/C_study/CplusAlgorithm_PNU2017/sampleData8/f1.out") ;
int largest_map_value(const map<string, int>& m)
{
    map<string, int>::const_iterator it = m.begin();
    int highest = it->second;
    for(map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        if(it->second > highest)
            highest = it->second;
    }
    return highest;
}

int main()
{

    int k = 0;
    inpStream >> k;
    
    string str ="";
    string tmpstr;
    while (inpStream >> tmpstr) {
        str+=tmpstr;
    }
    for (int i = 0; i < str.size() - k + 1; i++) {
        tmpstr =str.substr(i,k);
        int datacnt = mapData[tmpstr];
        mapData[tmpstr] = ++datacnt;
    }
    

    cout << largest_map_value(mapData);
    
    return 0;
}

