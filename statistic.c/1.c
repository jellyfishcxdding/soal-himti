#include <stdio.h>

FILE *fp;

void bubble(double arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main () {
    
    fp = fopen("Dataset.txt", "r");

    if(fp == NULL){
        return -1;
    }

    int T;
    fscanf(fp,"%d", &T);
    double angka[T];
    double sum = 0;
    for(int i = 0; i<T; i++){
        fscanf(fp,"%lf", &angka[i]);
        sum += angka[i];
    }
    fclose(fp);
   
    bubble(angka, T);


    double min = angka[0];
    double max = angka[T-1];
    double median;
    if(T%2 != 0){
        median = angka[T/2];
    }
    else{
        median = (angka[T/2-1] + angka[T/2])/2.00;
    }
    //findinng min 

   
    //fiding max

   

    double mean = sum/(double)T;


    printf("%.0lf %.0lf %.3lf %.3lf\n",min, max, mean,median);
    return 0;
}