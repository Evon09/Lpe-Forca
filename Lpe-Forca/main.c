#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

#include "Verifica.h"






main(){
    char palavra[60],letra=' ',palavra_[60],in[1]={' '},dica[60],letras[100]={' '},letrasaux[52]={"a b c d e f g h i j k l m n o p q r s t u v w x y z"},lixo[100];
    int tamanho, erro=0,acerto=0,acerto2,espaco=0,i=0,palavraaleatoria,tecla;

    PlaySound(TEXT("forca.wav"), NULL, SND_LOOP | SND_ASYNC);
    //config_Screen();

    system("mode con:cols=101 lines=30");
    SetConsoleTitle("UOF7 - FORCA 2019");

    tecla=telaInicial(tecla,palavra,dica,i,palavraaleatoria);


    //tecla=telaInicial(tecla);

    strcpy(palavra_,palavra); // transforma a palavra informada em array
    tamanho=strlen(palavra);
    espaco=linha(tamanho,palavra_,palavra,espaco,letra);

    erro=jogo(erro,tamanho,palavra_,palavra,acerto,letra,letrasaux,tecla,dica,espaco,acerto2);
    system("cls");
    printf("%d",erro);
    printf("%d--%d",acerto,tamanho);
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
