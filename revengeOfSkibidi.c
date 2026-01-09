#include <stdio.h>
#include <string.h>

int vowelCount(char arr[]){
    int len = strlen(arr);
    int count  = 0;
    for(int i = 0; i<len; i++){
        if(arr[i] == 'a' || arr[i] == 'u'|| arr[i] == 'e'|| arr[i] == 'i'|| arr[i] == 'o'){
            count++;
        }
    }

    return count;

}

int main () {
    int a,b;
    scanf("%d %d", &a,&b);

    // char arr[a][b+1];
    // for(int i = 0; i<a; i++){
    //     for(int j = 0; j<b;j++){
    //         scanf("%c", &arr[i][j]);
    //     }
    // }


    //better dibaca make string
    char arr[a][1005];
    for(int i = 0; i<a; i++){
        scanf("%s", arr[i]);
    }



    for(int i = 0; i< a-1; i++){
        for(int j = 0; j<a-i-1; j++){
            int doS = 0; // swap flag
            int c1 = vowelCount(arr[j]);
            int c2 = vowelCount(arr[j+1]);

            if(c1<c2){
                doS = 1;
            }
            
            else if(c1 == c2 &&  strcmp(arr[j], arr[j+1])<0){
                doS=1;
            }
            if(doS){
                char temp [1001];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1],temp);
            }

        }
    }

    for(int i = 0; i<a; i++){
        printf("%s\n", arr[i]);
    }
    




    return 0;

}
