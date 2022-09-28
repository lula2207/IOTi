#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char* open_file(char *local);

void char_to_int(char *, short *sinal);

short number_points(char* texto);

short valueRMS(short *sinal);

int main() {
    char* arquivo;
    char* texto;
    char *token, *aux;
    short valor;

    arquivo = "C:/Users/joao.lula/Documents/IOTi/Sprint1/sinal.txt";

    texto = open_file(arquivo);
    aux = open_file(arquivo);

    valor = number_points(aux);

    short sinal[valor];

    char_to_int(texto,sinal);

    

    short RMS = valueRMS(sinal);

    printf("Valor RMS:%d",RMS);

    printf("\nFim1");
    

    return 0;
}

char * open_file(char *local){

    FILE    *file;
    long    numbytes;
    char   *text;
    
    file = fopen(local, "r");

    if(file == NULL){
        return "nulo";
    }
    
    fseek(file, 0L, SEEK_END);
    numbytes = ftell(file);
    fseek(file, 0L, SEEK_SET);	
    
    text = (char*)calloc(numbytes, sizeof(char));	
    if(text == NULL)
        return "nula";

    fread(text, sizeof(char), numbytes, file);
    fclose(file);

    return text;
}

short number_points(char* texto){
    char* token; 
    short i=1; 

    token = strtok(texto,"\n");
    while(token!=NULL){
        token = strtok(NULL,"\n");
        i++;
    }

    return i;
}

void  char_to_int(char *texto, short *sinal){

    char* token; 
    short i=1; 

    token = strtok(texto,"\n");
    while(token!=NULL){
        sinal[i-1] = atoi(token);
        token = strtok(NULL,"\n");
        i++;
        
    }
}

short valueRMS(short* sinal ){

    // calculo do periodo 

    short T, aux1, aux2 = 1, i=1;
    int ciclo = 1;

   
    // considerando que qualquer ponto, retirando a crista e o vale, são 3 vezes vistos em 1 ciclo.  
    while(ciclo == 1){
        aux1 = sinal[1];
        i++;

        if(aux1 == sinal[i]){
            aux2++;
        }

        if(aux2 == 3)
        {
            ciclo = 0;
        }
    }
    T = i - 1; 

    double soma_aux = 0; 
    short rms;

    for (short j = 0; j<T;j++)
        soma_aux+=pow(sinal[j],2); 
    
    
    rms = (short)sqrt(soma_aux/T);



return rms;

}