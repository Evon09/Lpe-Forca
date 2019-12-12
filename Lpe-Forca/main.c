#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

#include "Verifica.h"
/*
inicializa(char letrasaux[52] ){
for(int i=0 ,alfa=97;i<52;i++,alfa++){
    if(i%2!=0){
       letrasaux[i]=alfa;

    }else{
        letrasaux[i]=' ';
    }


}




}*/





main(){
    char palavra[60],letra=' ',palavra_[60],in[1]={' '},dica[60],letras[100]={' '},letrasaux[52],inicializa[52]={"a b c d e f g h i j k l m n o p q r s t u v w x y z"},lixo[100];
    int tamanho, erro=0,acerto=0,acerto2,espaco=0,i=0,palavraaleatoria,tecla;

    PlaySound(TEXT("forca.wav"), NULL, SND_LOOP | SND_ASYNC);
    //config_Screen();


    SetConsoleTitle("UOF7 - FORCA 2019");
    do{
        system("mode con:cols=101 lines=34");

        tecla=telaInicial(tecla,palavra,dica,i,palavraaleatoria);
        strcpy(letrasaux,inicializa);
        erro=0;
        espaco=0;
        tamanho=0;

        //tecla=telaInicial(tecla);
        if(tecla==0||tecla==2){

            strcpy(palavra_,palavra); // transforma a palavra informada em array
            tamanho=strlen(palavra);
            //printf("%d",tamanho);
            //system("pause");
            espaco=linha(tamanho,palavra_,palavra,espaco,letra);

            erro=jogo(erro,tamanho,palavra_,palavra,acerto,letra,letrasaux,tecla,dica,espaco,acerto2);
            system("cls");
           // printf("%d",erro);
            //printf("%d--%d",acerto,tamanho);
                if(erro>4){
                    system("color 4f");
                    gameover();
                }
                else{
                        system("color 2f");
                        vencer();
                   }
                getch();
        }

    }while(tecla!=6);

    system("mode con:cols=30 lines=5");
    moldura(1,30,1,4);
    //printf("\n");
    gotoxy(10,2);printf("\b\bQue pena!! c(v_v)c");
    getch();

}
