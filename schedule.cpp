#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct work{
    int st,ed,w;
};

bool srt(const work& v1, const work& v2){
    return (v1.ed < v2.ed);
}

void schedule(vector<work>& a, int n, int res[][2]){
    int o_ed=0;
    for(int i=0;i<n;i++){
        if(o_ed < a[i].st){
            res[a[i].ed][0] = res[o_ed][0] + a[i].w - 10;
            res[a[i].ed][1] = res[o_ed][1] + a[i].ed - a[i].st + 1;
        }else{
            int j;
            for(j=a[i].st-1;j>0;j--){
                if(res[j][0] != 0) break;
            }
            if(res[j][0] + a[i].w - 10 > res[o_ed][0]){
                res[a[i].ed][0] = res[j][0] + a[i].w - 10;
                res[a[i].ed][1] = res[j][1] + a[i].ed - a[i].st + 1;
            }else if(res[j][0] + a[i].w - 10 == res[o_ed][0]){
                res[a[i].ed][0] = res[o_ed][0];
                res[a[i].ed][1] = min(res[j][1] + a[i].ed - a[i].st + 1, res[o_ed][1]);
            }else{
                res[a[i].ed][0] = res[o_ed][0];
                res[a[i].ed][1] = res[o_ed][1];
            }
        }
        o_ed = a[i].ed;
    }
}

int main(){
    int n;
    FILE *fp;
    fp = fopen("schedule.inp","r");
    fscanf(fp,"%d",&n);
    vector<work> a(n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%d %d %d",&a[i].st,&a[i].ed,&a[i].w);
    }
    fclose(fp);

    sort(a.begin(), a.end(), srt);

    int res[a[n-1].ed+1][2];
    memset(res, 0, sizeof(res));

    schedule(a, n, res);

    fp = fopen("schedule.out","w");
/*
    for(int i=0;i<n;i++)
        fprintf(fp,"%d %d %d\n", a[i].st, a[i].ed, a[i].w);
    fprintf(fp,"\n");
    for(int i=1;i<a[n-1].ed+1;i++)
        fprintf(fp,"(%d, %d) ", res[i][0],res[i][1]);
    fprintf(fp,"\n");
*/
    fprintf(fp,"%d %d",res[a[n-1].ed][0] + 10,res[a[n-1].ed][1]);
    fclose(fp);
    return 0;
}
