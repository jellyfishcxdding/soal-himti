#include <stdio.h>

int SumDig(int n){
    if(n == 0){
        return 0;
    }
    return (n%10) + SumDig(n/10);
}



FILE *fp;

typedef struct{
    int ID;
    int rewatch;
    int rate;
}alomani;


alomani a[105];
int main () {
    
     fp = fopen("AlomaniAlomani.txt", "r");
    if(fp == NULL){
        return -1;
    }
    int T;
    fscanf(fp, "%d", &T);

    for(int i = 0; i<T; i++){
        fscanf(fp, "%d#%d#%d\n", &a[i].ID, &a[i].rewatch, &a[i].rate );
    }
     fclose(fp);
    for(int i = 0; i<T-1; i++){
        for(int j = 0; j<T-i-1; j++){
            int count1 = SumDig(a[j].ID);
            int count2 = SumDig(a[j+1].ID);
            int s =0;
            if(a[j].rate < a[j+1].rate){
                s =1;
            }
            else if(a[j].rate == a[j+1].rate && a[j].rewatch < a[j+1].rewatch ){
                s=1;
            }
            else if(a[j].rate == a[j+1].rate && a[j].rewatch == a[j+1].rewatch && count1<count2) {
                s =1;
            }
            if(s){
                alomani temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i = 0 ; i<T; i++){
        printf("%06d\n", a[i].ID);//asking for 6 digit typeshiii, dan 0 ini buat nandain adanya 0 di depan
    }
    return 0;
}