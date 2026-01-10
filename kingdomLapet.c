#include <stdio.h>
#include <string.h>



typedef struct{
    char ID;
    int area;
}Kingdom;

int visited[105][105];
char grid[105][105];
    int N,M;

int FloodFill(int row, int col){

    //cek validasi area
    //array dimumai dari 0
    if(row < 0|| col<0|| row >= N||col>=strlen(grid[0])) return 0;

    if(grid[row][col] == '#' ||visited[row][col] == 1) return 0;


    visited[row][col] =1;
    int luas = 1;
    // maju mundur depan belakang
 
    luas +=FloodFill(row+1, col);
    luas += FloodFill(row-1, col);
   luas += FloodFill(row, col+1);
    luas += FloodFill(row, col-1);
    return luas;
}

int main () {

    scanf("%d %d", &N, &M);

    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<M; j++){
    //         scanf("%c", &grid[i][j]);
    //     }
    //     getchar();
    // }

    //approach lebih baik

    for(int i = 0; i<N; i++){
        scanf("%s", grid[i]);
    }
    memset(visited, 0, sizeof(visited));

    Kingdom k[105];
    int count = 0;


    for(int i = 0; i<N; i++){
        int len = strlen(grid[i]);
        for(int j = 0; j<len; j++){
            if(grid[i][j]>= 'a' && grid[i][j] <= 'z' && visited[i][j] == 0){
                k[count].area  = FloodFill(i, j);

                k[count].ID = grid[i][j];

                     count++;
            }
   
        }
    }
    

    for(int i = 0; i<count -1; i++){
        for(int j = 0; j<count -i-1; j++){
            if(k[j].ID > k[j+1].ID){
                Kingdom temp = k[j];
                k[j] =k[j+1];
                k[j+1] = temp;
            }
        }
    }


    for(int i = 0; i<count; i++){
        printf("%c %d\n", k[i].ID, k[i].area);
    }



    return 0;
}