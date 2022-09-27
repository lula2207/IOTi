#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* open_file(char *local);

void char_to_int(char *str, short *sinal);

int main() {
    char* arquivo;
    char* output;
    int i = 1, sinal;
    char *token;
   

    arquivo = "C:/Users/joao.lula/Documents/IoTI/Sprint1/sinal.txt";

    output = open_file(arquivo);

    printf(output);

    printf("oi");
    token = strtok(output, "\n");
    sinal = atoi(token);
    
    while(token != NULL){
        token = strtok(NULL, "\n");
        sinal = atoi(token);
        i++;
        printf("\n%d",sinal);

    }

    
    printf("\n%d",sinal);

    printf("\nFim89");

    return 0;
}

char * open_file(char *local){

    FILE    *file;
    long    numbytes;
    char   *text;
    
    file = fopen(local, "r");

    if(file == NULL){
        return "oi";
    }
    
    fseek(file, 0L, SEEK_END);
    numbytes = ftell(file);
    fseek(file, 0L, SEEK_SET);	
    
    text = (char*)calloc(numbytes, sizeof(char));	
    if(text == NULL)
        return "oi";

    fread(text, sizeof(char), numbytes, file);
    fclose(file);

    return text;
}

