#include<stdio.h>
#include<stdbool.h>

void quickSort(int cantidad, int lista[]);
bool comprobarlista(int lista[], int cantidad);

int main(){
    int cantidad=0;


    printf("Ingrese la cantidad de elementos que va a tener la lista:  ");
    scanf("%d", &cantidad);

    int lista[cantidad];

    printf("Vamos a rellenar la lista.\n");
    for(int i=0; i < cantidad; i++){
        printf("lista[%d] = ", i+1);
        scanf("%d", &lista[i]);
    }


    printf("\n\nIngresaste los numero:\n");
    for(int i=0; i < cantidad; i++){
        printf("lista[%d]: %d\n", i+1, lista[i]);
    }

    quickSort(cantidad, lista);


    return 0;
}





void quickSort(int cantidad, int lista[]){
    
    int pivote = 99, listaMenor[cantidad], listaMayor[cantidad], i = 0, e = 1, j = 0, k = 0;
    bool valor;

    valor = comprobarlista(lista, cantidad); //compruebo si la lista esta ordenada. si devuelte true la lista ya esta ordenada! si devuelve false la lista debe ordenarse!

    if(valor == true){
        printf("La lista esta ordenada!!");
    }
    else{
        printf("La lista esta desordenada!!!\n\n");
        
        pivote = lista[0];

        for(int f=0; f < cantidad; f++){// relleno mis dos listas con 99 para saber cuantos elementos se van a guardar en cada lista
            listaMenor[f] = 99;
            listaMayor[f] = 99;
        }

        listaMayor[j] = pivote; // para que poner al pivot al principio de la listaMayor
        j = 1;
        for(i = 1 ; i < cantidad; i++){
            
            if(pivote < lista[i]){
                printf("\n\n-*-*-*- %d < %d", pivote, lista[i]);

                listaMayor[j] = lista[i];
                j = j +1;
            }
            else{
                printf("\n\n---- %d < %d", pivote, lista[i]);
                listaMenor[k] = lista[i];
                k = k +1;
            }

        }

//////////////////////////

        printf("\nTermine de armar las dos listas, vamos a verlas\n\nj=%d\nk=%d\n\n\n", j, k);
    
        printf("\n\n\nviendo la lista de menores:\n");
        for(int h = 0; h < k; h++){
            printf("ListaMenor[%d] = %d\n", h,listaMenor[h]);
        }
        
        printf("\n\n\nviendo la lista de mayores:\n");
        for(int h = 0; h < j; h++){
            printf("ListaMayores[%d] = %d\n", h,listaMayor[h]);
        }
        // k = menor ;;; f = para menores
        // j = mayor ;;; g = para mayores

        // tengo que concatenar las listas
        /*

        Para concatenar creo un arreglo del tamaño original

        hago un bucle for de 0 hasta la cantidad y voy rellenanlo el nuevo arreglo con los valores del arreglo de menores hasta llegar a la variable k

        cuando llegue a la variable k tengo que seguir rellenanlo el arreglo con el array de mayores hasta llegar a la variable j 

        tendria que rellenarse bien!!! Para esto voy a hacer una funcion!

        */
        int ListaAux[cantidad];
        
        int f = 0, g = 0;
        for(i =0; i < cantidad; i++){
        
            if(i >= k){
                //guardo en la lista auxiliar los elementos de la lista de mayores 
                ListaAux[i] = listaMenor[f];
                printf("{-{-{-{-{-{listaAux[%d]: listaMenor[%d]\n",ListaAux[i], listaMenor[f] );
                printf("f = %d\n", f);
                f = f + 1;
            }
            
            //guardo en la lista auxiliar los elementos de la lista de mayores 
            ListaAux[i] = listaMayor[g];
            printf("{-{-{-{-{-{listaAux[%d]: listaMenor[%d]\n",ListaAux[i], listaMenor[g] );
            g++;
            printf("g = %d\n", g);


        }


//////////////////////
        printf("\n\n\nViendo el nuevo array ListaAux:\n\n\n");
        for(int i=0; i < cantidad; i++){
            printf("listaAux[%d]: %d\n", i, ListaAux[i]);
        }



    }

   


}




bool comprobarlista(int lista[], int cantidad){
    bool valor=true;
    int i=0, e=0;

    printf("\n\nCOMPROBANDO SI EL ARRAY ESTA ORDENADO....\n\n");

    for(i = 0; i < cantidad-1; i++){

        if(lista[e] < lista[e+1]){
            e++;
        }
        else{
            i = cantidad;    
            valor = false;
        }
        
    }    
    return valor;
}
