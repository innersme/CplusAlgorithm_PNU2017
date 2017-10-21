//
//  main.cpp
//  CplusAlgorithms
//
//  Created by MJMac on 2017. 10. 18..
//  Copyright © 2017년 innersme. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

string res[1001][1001];

void lcs(char* s1, char* s2,int* w){
    
    // strlen 사용, s1길이, s2길이
    int n1=strlen(s1),n2=strlen(s2);
    
    // dp행렬 + 널문자
    int dp[n1+1][n2+1];
    
    // 초기값 0으로 초기화
    for(int i=0;i<=n1;i++) dp[i][0]=0;
    for(int i=0;i<=n2;i++) dp[0][i]=0;
    
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            // 만약 일치하지 않는다면,
            if(s1[i-1] != s2[j-1]){
                
                
                
                if(dp[i-1][j] == dp[i][j-1]){
                    if(res[i][j-1] > res[i-1][j])
                        res[i][j] = res[i-1][j];
                    else
                        res[i][j] = res[i][j-1];
                }else{
                    if(dp[i-1][j] > dp[i][j-1])
                        res[i][j] = res[i-1][j];
                    else
                        res[i][j] = res[i][j-1];
                    //
                    
                }
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            
        else
            
        {
                switch(s1[i-1]){
                        
                    //string A
                    case 'A':
                        
                        
                        dp[i][j]=max(dp[i-1][j-1]+w[0],max(dp[i][j-1],dp[i-1][j]));
                        if(dp[i-1][j-1] == dp[i-1][j] == dp[i][j-1] || dp[i-1][j-1] + w[0] == dp[i][j]){
                            res[i][j] = res[i-1][j-1] + 'A';
                        }else{
                            if(dp[i-1][j] == dp[i][j-1]){
                                if(res[i][j-1] > res[i-1][j])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }else{
                                if(dp[i-1][j] > dp[i][j-1])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }
                        }
                        break;
                        
                    
                    case 'G':
                        dp[i][j]=max(dp[i-1][j-1]+w[1],max(dp[i][j-1],dp[i-1][j]));
                        if(dp[i-1][j-1] == dp[i-1][j] == dp[i][j-1] || dp[i-1][j-1] + w[1] == dp[i][j]){
                            res[i][j] = res[i-1][j-1] + 'G';
                        }else{
                            if(dp[i-1][j] == dp[i][j-1]){
                                if(res[i][j-1] > res[i-1][j])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }else{
                                if(dp[i-1][j] > dp[i][j-1])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }
                        }
                        break;
                        
                        
                    case 'T':
                        dp[i][j]=max(dp[i-1][j-1]+w[2],max(dp[i][j-1],dp[i-1][j]));
                        if(dp[i-1][j-1] == dp[i-1][j] == dp[i][j-1] || dp[i-1][j-1] + w[2] == dp[i][j]){
                            res[i][j] = res[i-1][j-1] + 'T';
                        }else{
                            if(dp[i-1][j] == dp[i][j-1]){
                                if(res[i][j-1] > res[i-1][j])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }else{
                                if(dp[i-1][j] > dp[i][j-1])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }
                        }
                        break;
                        
                        
                    case 'C':
                        dp[i][j]=max(dp[i-1][j-1]+w[3],max(dp[i][j-1],dp[i-1][j]));
                        if(dp[i-1][j-1] == dp[i-1][j] == dp[i][j-1] || dp[i-1][j-1] + w[3] == dp[i][j]){
                            res[i][j] = res[i-1][j-1] + 'C';
                        }else{
                            if(dp[i-1][j] == dp[i][j-1]){
                                if(res[i][j-1] > res[i-1][j])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }else{
                                if(dp[i-1][j] > dp[i][j-1])
                                    res[i][j] = res[i-1][j];
                                else
                                    res[i][j] = res[i][j-1];
                            }
                        }
                        break;
                }
            }
        }
    }
    /*
     for(int i=1;i<=strlen(s1);i++){
     for(int j=1;j<=strlen(s2);j++)
     fprintf(fp,"%4d ",dp[i][j]);
     fprintf(fp,"\n");
     }
     
     for(int i=1;i<=strlen(s1);i++){
     for(int j=1;j<=strlen(s2);j++)
     fprintf(fp,"%4s ",res[i][j].c_str());
     fprintf(fp,"\n");
     }
     */
}

int main(){
    char s1[1001],s2[1001];
    int w[4];
    FILE *fp;
    
    fp = fopen("gene.inp","r");
    fscanf(fp,"%s %s %d %d %d %d",s1,s2,w,w+1,w+2,w+3);
    fclose(fp);
    
    lcs(s1,s2,w);
    
    fp = fopen("gene.out","w");
    fprintf(fp,"%s",res[strlen(s1)][strlen(s2)].c_str());
    fclose(fp);
    
    return 0;
}
