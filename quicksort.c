#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int separa(int v[], int baixo, int alto, int *loop) {
    int x = v[alto];
    int i = baixo - 1; // índice mais alto para o lado + baixo

    // processa cada elemento
    for (int j = baixo; j <= alto - 1; j++) {
        (*loop)++;
        // cada elemento um loop ++
        if (v[j] <= x) {
            i = i + 1;       // índice de um novo local no lado baixo
            troca(&v[i], &v[j]); // coloca este elemento lá
        }
    }

    troca(&v[i + 1], &v[alto]); // pivô entra logo à direita do lado baixo
    return i + 1;            // novo índice do pivô
}

void quicksort(int v[], int baixo, int alto, int *loop)
{
    while (baixo < alto)
    {
        int j = separa(v, baixo, alto, loop);
        quicksort(v, baixo, j - 1, loop);
        baixo = j + 1;
    }
}

int main(){

    //mude o tamanho da amostra para o número de números em cada arquivo tipo 100, 200, 300, etc...
    int amostratam = 100;

    int *v = malloc(10* sizeof(int));

    int looptotal = 0;
    double tempototal = 0;

    for(int w = 0; w < 10;w++){
        for(size_t i = 0; i <= amostratam;i++){
        scanf("%d", &v[i]);
        }

    clock_t antes, depois;
    int loop = 0;
    
    antes = clock();
    quicksort(v, 0, amostratam, &loop);
    depois = clock();
    double mediaseg = (double)(depois - antes)/ CLOCKS_PER_SEC;
    double mediasegg = mediaseg*1000;

    //se for fazer testes só desfazer esse comentario para ver os números que estão sendo lidos pelo código
    /*
    for(size_t i = 0; i <= 100;i++){
        printf("%i\n", v[i]);
    }
    */


    printf("Número de loops: %d\n", loop);
    printf("Tempo: %f segundos\n", mediasegg);

    looptotal = looptotal + loop;
    tempototal = tempototal + mediasegg;
    }

    printf("Número total de loops: %d\n", looptotal);
    printf("Tempo total: %f segundos\n", tempototal);



    return 0;
}
