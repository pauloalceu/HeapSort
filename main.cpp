#include <cstdlib>
#include <iostream>

using namespace std;

//procedimento que realiza a troca de posições
void swap(int v[], int j, int aposJ){
     
    //crio uma variavel auxiliar que recebe o valor da posição j 
    int aux = v[j];
    //coloco o valor da posição aposJ na posição j
    v[j] = v[aposJ];
    //coloco o valor auxiliar na posição aposJ
    v[aposJ] = aux;
}

//procedimento que faz a "heapficação", ou seja, reorganiza montando o heap máximo
void maxHeapify(int v[], int pos, int n){
     
    //pego a posição máxima do heap  
    int max = 2 * pos + 1;
    //pego a direita do heap
    int right = max + 1;    
    
    //verifico se o máximo não ultrapassa do tamanho do vetor
    if (max < n){
            
        //verifico a posição direita é menor que o tamanho do vetor e se a o 
        //vetor na posicao maxima é menor que o vetor na posição direita    
        if (right < n && v[max] < v[right]){
            //assim o máximo recebe a posicao right, pois ela não era realmente
            //o nó máximo do heap      
            max = right;
        }
            
        //verifico se a posicao máxima é maior que a posição de entrada
        if (v[max] > v[pos]){
            //realizo a troca de posições entre o máximo e pos
            swap(v, max, pos);
            //tento reorganizar o heap novamente
            maxHeapify(v, max, n);
        }
    }
}

//método responsável pela construção do heap máximo
void buildMaxHeap(int v[], int n){
     
    //percorro os items do vetor, montando o heap máximo 
    //n / 2 - 1: por causa do tamanho do heap. Ex: se o heap tiver 7 nos, 
    //seria 7/2 = 3 - 1 = 2, altura da árvore é 2. Porém, o laço vai ate >= 0,
    //assim sendo a altura da árvore é 3, começando de zero.
    for (int i = n / 2 - 1; i >= 0; i--){
       //reorganizo o heap máximo 
       maxHeapify(v, i, n);
    }
}

//procedimento, como o proprio nome diz, faz a ordenação
void heapsort(int v[], int n){
     
    //construo o heap máximo 
    buildMaxHeap(v, n);
    
    //percorro o o vetor da posição n - 1 até 0
    for (int i = n - 1; i > 0; i--){
        //realizo a troca de posições
        swap(v, i, 0);
        //reorganizo o heap máximo
        maxHeapify(v, 0, --n);
    }     
}

int main(int argc, char *argv[])
{
    int tam = 0;
    printf("%s", "Informe o tamanho da lista: ");
    scanf("%d", &tam);
    
    int lista[tam];
    for (int i = 0; i < tam; i++){
    
        printf("%s %d %s", "Informe o item ", i, " da lista: ");
        scanf("%d", &lista[i]);
        
    }
    
    //chamo o procedimento de heap sort
    heapsort(lista, tam);
    
    printf("%s", "\n");
    for(int j = 0; j < tam; j++){
            
            printf("%d  ", lista[j]);
                    
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
