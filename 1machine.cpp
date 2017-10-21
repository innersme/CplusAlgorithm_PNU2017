//
//  mach.cpp
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
    // ci: 지불비용, di: 마감날짜
    int ci, di;
};

// 정렬기준 c1
bool srt(const machine& v1, const machine& v2){
    return (v1.ci > v2.ci);
}

int main()
{
    int N, T, k;
    
    int i = 0;
    ifstream fin("/Users/innersme/C_study/CplusAlgorithms/CplusAlgorithms/2.inp");
    fin >> N >> T >> k;
    
    // 벡터생성 a:입력, b:나머지값
    vector <machine> a(N);
    vector <machine> b(N);
    
    for (int i = 0; i< N; i++) {
        fin >> a[i].ci >> a[i].di;
    }
    fin.close();
    sort(a.begin(), a.end(), srt);
    
    // 배열 생성
    int ** arr = new int* [k];
    for (int i = 0; i < k; i++) {
        arr[i] = new int [T];
    }
    
    // 배열 초기화
    for (int i = 0; i< T; i++) {
        for(int j = 0 ; j < k ; j ++)
        {
            arr[j][i] = 0;
        }
    }
    
    
    //logic
    //idx = 0부터 시작
    i =0;
    //j = b_idx
    int j = 0;
    // a에 넣을 count
    int count = 0 ;
    // 배열 총갯수 까지
    while (count < T*k) {
        // 초기값 row = 0 , col = Max;
        int row = 0;
        int col = a[i].di-1;
        
        while(1)
        {
            if (col < 0) {
                b[j] = a[i]; j++;
                break;
            }
            else if (row == k)
            {
                col--; row = 0;
                
            }
            else
            {
                if (arr[row][col] == 0)
                {
                    cout << row << " " << col << " "<< a[i].di<<" " << count << endl;
                    arr[row][col] = a[i].di; count++;
                    break;
                }
                else
                {
                    if (row < k)
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
    
    int sum = 0;
    for (int row = 0; row <k; row++) {
        for (int col = 0; col < T; col++) {
            sum += arr[row][col];
        }
    }
    cout << b[0].ci << " " << b[0].di << endl;
    // di = 제일 작은 di 값
    int di = b[0].di;
    int *sumArr = new int[di];
    for (int i = 0 ; i < di; i++) {
        sumArr[i] = 0;
    }
    
    for (int i = 0; i < di; i++) {
        arr[k-1][i] = b[0].ci;
        for (int row = 0; row < k; row++) {
            for (int col = 0; col <T; col++) {
                sumArr[i] += arr[row][col];
            }
        }
    }
    
    int sum2 = 0;
    for (int i = 0; i < di; i++) {
        sum2 = max(sum2, sumArr[i]);
    }
    
    if (sum == sum2) {
        sum2 = sum2 - b[0].di;
    }
    
    cout << sum << " " << sum2 << endl;
    
    
    for (int i = 0; i < k; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete [] sumArr;
    
    return 0;
}
