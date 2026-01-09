#include <stdio.h>


int main () {
    int N, M;
    scanf("%d %d", &N, &M);


    int a[N];

    for(int i = 0; i<N; i++){
        scanf("%d", &a[i]);
    }

    //query position finding

    for(int i = 0; i<M; i++){
        int find;
        scanf("%d", &find);

        int left = 0;
        int right = N-1;
        int ans = -1;
        while(left<=right){
            int mid = left + (right - left)/2;

            if(a[mid]== find){
                ans = mid;
                right = mid-1; //find until we get the leftmost index
            }
            else if(a[mid] > find){
                left = mid +1; //in dsc order sometimes the number that we want to find is to big
            }

            else {
                right = mid-1;
            }
        }

        if(ans != -1){
            printf("MBG %d was located in %d meters!\n", find, ans+1);


        }

        else {
            printf("MBG %d was not located!\n", find);
        }
    }


    




    return 0;
}