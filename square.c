#include <stdio.h>
#include <stdlib.h>
#define mininpNum 5
#define maxinpNum 1000
#define maxNum 1000000

int main()
{
    FILE *fp;
    fp = fopen("square.inp", "r");
    
    int i, j, k, tmp, flag = 0;
    int inpNum;
    /* 배열 초기화 */
    int ansArr[maxinpNum];
    
    fscanf(fp,"%d", &inpNum);
    /* 동적할당 */
    int * numArr =(int*) malloc(sizeof(int) * inpNum);
    
    /* 배열 값 지정*/
    for (i = 0; i < inpNum; i++) {
        fscanf(fp,"%d", &numArr[i]);
    }
    fclose(fp);
    
    /* 배열 정렬 */
    for (i = 0; i < inpNum ; i++) {
        for (j = 0; j < inpNum-i-1 ; j++) {
            if (numArr[j] > numArr[j+1]) {
                tmp = numArr[j];
                numArr[j] = numArr[j+1];
                numArr[j+1] = tmp;
            }
        }
    }
    
    /* 주요 로직 */
    for (i = 2 ; i < inpNum; i++) {
        for (j = 1 ; j < i; j++) {
            for (k = 0 ; k < j; k++) {
                if (numArr[k]*numArr[k] + numArr[j]*numArr[j] == numArr[i]) {
                    /* 반복 (flag-1) 이미 있다면, continue */
                    if (ansArr[flag-1] == numArr[i]) {
                        continue;
                    }
                    else
                    {
                        ansArr[flag] = numArr[i];
                        flag++;
                    }
                }
            }
        }
    }
    
    FILE *ffp;
    ffp = fopen("square.out", "w");
    
    if (flag == 0) {
        fprintf(ffp,"%d", flag);
    }
    
    else
    {
        for (i = 0 ; i < flag; i++) {
            fprintf(ffp,"%d ", ansArr[i]);
        }
    }
    fclose(ffp);
    
    return 0;
}
