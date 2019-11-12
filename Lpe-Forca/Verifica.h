#include <stdio.h>

int linha(int tamanho,char palavra_[tamanho-1],char palavra[],int espaso,char letra){

    for(int cont=0;cont<tamanho;cont++){ // printa o inicio da forca com os espaços em branco
        if(isalpha(palavra[cont])){

            palavra_[cont]='_';
        }

            if(isspace(palavra_[cont])){
           // palavra_[cont]=' ';

            espaso++;
            }

        //printf("%c ",palavra_[cont]);
    }

return(espaso);
}
int Verifica(int tamanho,char palavra_[],char palavra[],int acerto,char letra,int erro){
    for(int cont=0;cont<tamanho;cont++){
            if(palavra[cont]==letra){
                palavra_[cont]=letra;
                palavra[cont]='*';
                acerto++;
            }


        }
     return(acerto);

}
void tecla2(char *palavra,char *dica){
    int verifica=0;

    do{
        system("cls");
        fflush(stdin);

        gotoxy(56,15);

        printf("Informe Uma Palavra: ");
        scanf("%[A-Z,a-z, ]s",palavra);
        fflush(stdin);
        gotoxy(56,19);
        printf("Informe Uma Dica: ");
        scanf("%[A-Z,a-z, ,0-9]s",dica);

        for(int i=0;i<=strlen(palavra);i++){
            if(isalpha(palavra[i]))
                verifica=1;
                break;
            }
        if(verifica>=1){
            break;
        }
        system("cls");
        fflush(stdin);
        gotoxy(56,15);

        printf("\t\tPALAVRA INVALIDA");
        Sleep(3000);

    }while(1);

}

void tecla1(char *palavra,char *dica,int i,int palavraaleatoria){


                  FILE *palavras;
                  FILE *dicas;
                  dicas =fopen("dicas.txt","r");
                  palavras =fopen("palavra.txt","r");
                  srand(time(NULL));


                  palavraaleatoria=i;
                //printf("%d", palavraaleatoria);
               // palavraaleatoria=rand()%palavraaleatoria;
                //printf("%d", palavraaleatoria);
                  palavraaleatoria=rand()%20;


                while(fgets(palavra, 60, palavras)!= NULL&& fgets(dica, 60, dicas)!=NULL&&i<=palavraaleatoria){
                    i++;
                }
                fclose(dicas);fclose(palavras);

            }

int jogo(int erro,int tamanho,char *palavra_,char *palavra,int acerto,char *letra,char *letrasaux,int tecla,char *dica,int espaco,int acerto2){
do{

            system("cls");
            /*printf("%d\n",erro);
            printf("%d--%d",acerto,tamanho);
            printf("\n%d",tecla);*/

            forcadesenha(erro);

            gotoxy(56,21);
            for(int cont=0;cont<tamanho;cont++){
                printf("%c ",palavra_[cont]);
            }
            acerto=Verifica(tamanho,palavra_,palavra,acerto,letra,erro);
            printf("A palavra tem :%d letras",tamanho-espaco);
            gotoxy(56,22);
            printf("A Dica e: %s",dica);
            gotoxy(56,23);

            for(int i=0;i<52;i++){
                if(letra==letrasaux[i] && letrasaux[i]!=' '){
                    letrasaux[i]='#';
                    }
            }

            gotoxy(56,24);
            printf("Letras usadas:");
            for(int i=0,j=0; i <strlen(letrasaux); i++) {

                if(i<30) {
                    gotoxy(56+i,25); printf("%c ",letrasaux[i]);
                }
                else{
                    gotoxy(60+j,26); printf("%c ",letrasaux[i]);
                    j++;
                }
            }
            printf("\n");
            gotoxy(56,27);
            printf("Digite uma letra:");
            letra=getch();
            Beep(100,10);
            acerto=Verifica(tamanho,palavra_,palavra,acerto,letra,erro);
            system("cls");
            if(acerto2==acerto){
                erro++;
            }
            acerto2=acerto;

            if(acerto == tamanho || (tecla==0 && tamanho-1==acerto))
            break;
            if(erro>5)
            break;

}while(1);
return(erro);

}



