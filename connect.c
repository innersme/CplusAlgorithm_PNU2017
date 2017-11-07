#include <stdio.h>
#include <stdlib.h>

double sqrtInteger(double num)
{
    double temp = 1;
    
    while (-0.01 > (temp * temp - num) || (temp * temp - num) > 0.01)
    {
        temp = 0.5 * (temp + num / temp);
    }
    
    return temp;
}

int main()
{
    FILE *fp;
    fp = fopen("connect.inp", "r");
    int k=1;
    int j=0;
    int ans;
    // a,b,c 는 계수
    double qans[1000];
    double t=0;
    //double i = -1;
    double NumArr[9] = {0, };
    double AnsArr[3] = {0, };
    double AAns = 0.0;
    double *anss;
    anss = &AAns;
    /* 0,1,2 점A 3,4,5 점B */
    
    for (j = 0; j < 9; j++) {
        fscanf(fp,"%lf", &NumArr[j]);
    }
    
    // 배열 등록 완료
    fclose(fp);

    for (j = 0; j < 3; j++) {
        AnsArr[j] = (1-t)*NumArr[j+3] + t*NumArr[j];
    }
    
    AAns = qans[0]=sqrtInteger((AnsArr[0]-NumArr[6])*(AnsArr[0]-NumArr[6]) + (AnsArr[1] - NumArr[7])*(AnsArr[1] - NumArr[7]) + (AnsArr[2]- NumArr[8])*(AnsArr[2]- NumArr[8]));
    for (t = 0.001; t < 1; t+=0.001) {
        for (j = 0; j < 3; j++) {
            AnsArr[j] = (1-t)*NumArr[j+3] + t*NumArr[j];
        }
        qans[k]=sqrtInteger((AnsArr[0]-NumArr[6])*(AnsArr[0]-NumArr[6]) + (AnsArr[1] - NumArr[7])*(AnsArr[1] - NumArr[7]) + (AnsArr[2]- NumArr[8])*(AnsArr[2]- NumArr[8]));
        if (AAns > qans[k]) {
            AAns = qans[k];
        }
        else
        {
        }
        k++;
    }
    
    ans = (int) *anss;
    
    FILE *ffp;
    ffp = fopen("connect.out", "w");
    fprintf(ffp,"%d",ans+1);
    fclose(ffp);

    /*
    FILE *ffp;
    ffp = fopen("connect.out", "w");
    fprintf(ffp,"%d", (int)sqrt(pow(AnsArr[0]-NumArr[6], 2) + pow(AnsArr[1] - NumArr[7], 2) + pow(AnsArr[2]- NumArr[8], 2))+1);
    fclose(ffp);
     */
    
    //printf("%f, %f",t, sqrt((AnsArr[0]-NumArr[6])*(AnsArr[0]-NumArr[6]) + (AnsArr[1] - NumArr[7])*(AnsArr[1] - NumArr[7]) + (AnsArr[2]- NumArr[8])*(AnsArr[2]- NumArr[8])));
    return 0;
}
