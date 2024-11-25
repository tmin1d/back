#include <stdio.h>

int main(){
    int all[9][9];
    int max = 0;
    int arr_i = 0;
    int arr_j = 0;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &all[i][j]);
            if(max <= all[i][j]){
                max = all[i][j];
                arr_i = i + 1;
                arr_j = j + 1;
            }
        }
    }
    
    printf("%d \n", max);
    printf("%d %d", arr_i, arr_j);
}
