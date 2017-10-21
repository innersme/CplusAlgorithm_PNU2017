//
//  machine.cpp
//  CplusAlgorithms
//
//  Created by MJMac on 2017. 10. 20..
//  Copyright © 2017년 innersme. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class machine{
public:
    int pi, di;
};

bool srt(const machine& v1, const machine& v2){
    return (v1.pi > v2.pi);
}

bool srt2(const machine& v1, const machine& v2){
    return (v1.di > v2.di);
}

int main()
{
    int N, K, t;
    
    int i = 0;
    //ifstream fin("/Users/innersme/C_study/CplusAlgorithms/CplusAlgorithms/1.inp");
    ifstream fin("machine.inp");
    
    fin >> N >> t >> K;
    
    // 나머지 값 입력
    vector <machine> c(N);
    vector <machine> b(N);
    vector <machine> a(N);
    
    for (int i = 0; i< N; i++) {
        fin >>c[i].pi >> c[i].di;
    }
    fin.close();
    
    sort(c.begin(), c.end(), srt2);
    
    for (int i = 0; i < N; i++) {
        a[i] = c[i];
    }
    
    sort(a.begin(), a.end(), srt);
    
    /*
    ofstream fout("/Users/innersme/C_study/CplusAlgorithms/CplusAlgorithms/sampleData6/out.out");
    
    
    fout << N << " " << t << " " <<K << endl;
    for (int i = 0; i< N; i++) {
        fout << a[i].pi <<" " << a[i].di << endl;
    }
    fout.close();*/
    
    // 배열 생성
    int ** arr = new int* [K];
    for (int i = 0; i < K; i++) {
        arr[i] = new int [t];
    }
    
    // 배열 초기화
    for (int i = 0; i< t; i++) {
        for(int j = 0 ; j < K ; j ++)
        {
            arr[j][i] = 0;
        }
    }
    
    i =0;
    int j = 0; int count = 0 ;
    while (count < t*K) {
        
        int row = 0;
        int col = a[i].di-1;
        
        while(1)
        {
            if (col < 0) {
                b[j] = a[i]; j++;
                break;
            }
            else if (row == K)
            {
                col--; row = 0;
                
            }
            else
            {
                if (arr[row][col] == 0)
                {
                    // cout << row << " " << col << " "<< a[i].pi<<" " << count << endl;
                    arr[row][col] = a[i].pi; count++;
                    break;
                }
                
                else
                {
                    if (row < K)
                    {
                        row++;
                    }
                }
            }
        }
        i++;
    }
    
    while (i<N) {
        b[j] = a[i];
        i++; j++;
    }
    
    cout << b[0].pi << " " << b[0].di << endl;
    
    int di = b[0].di;
    
    int sum = 0;
    for (int row = 0; row < K; row++) {
        for (int col = 0; col < t; col++) {
            sum += arr[row][col];
        }
    }
    
    int *sumArr = new int[di];
    for (int i = 0 ; i < di; i++) {
        sumArr[i] = 0;
    }
    
    
    for (int i = 0; i < di; i++) {
        arr[K-1][i] = b[0].pi;
        for (int row = 0; row < K; row++) {
            for (int col = 0; col < t; col++) {
                sumArr[i] += arr[row][col];
            }
        }
    }
    
    int sum2 = 0;
    for (int i = 0; i < di; i++) {
        sum2 = max(sum2, sumArr[i]);
    }
    if (sum == sum2) {
        sum2 = sum2 - b[0].pi;
    }
    
    //ofstream fout("/Users/innersme/C_study/CplusAlgorithms/CplusAlgorithms/machine.out");
    ofstream fout("machine.out");
    fout << sum << " " << sum2<< endl;
    
    delete []sumArr;
    for (int i = 0; i < K; i++)
        delete []arr[i];
    delete [] arr;
    
    return 0;
}
