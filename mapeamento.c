#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main (){

char matriz[16][16];char f;
for(int i=0;i<16;i++){
    for(int j=0; j<16;j++){
        matriz[i][j]= 'O';
    }
}
// for(int i=0;i<16;i++){
//     for(int j=0; j<16;j++){
//         printf("  %c",matriz[i][j]);
//     }
//     printf("\n");
// }
for(int m=0,n=0;m<16;m++,n++){    
    matriz[m][n] = 'A';
    if(m > 1){
        matriz[m-2][n-2] = 'O';
    }
    matriz[15-m][n] = 'C';
    if(m > 1){
        matriz[17-m][n-2] = 'O';
    }
    for(int i=0;i<16;i++){
        printf("\t");
        for(int j=0; j<16;j++){
            printf("  %c",matriz[i][j]);
        }
        printf("\n");
    }
    scanf("\n%c\n",&f);
}

    return 0;
}