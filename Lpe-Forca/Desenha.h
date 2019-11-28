#include <stdio.h>

void moldura(int ci, int cf, int li, int lf){///Funçao criada Por Carlos ^_^
    int l,c;
    for (c = ci + 1; c < cf; c++){
        gotoxy(c,li);printf("%c",205);
        gotoxy(c,lf);printf("%c",205);
    }

    for (l = li + 1; l < lf ; l++){
        gotoxy(ci,l);printf("%c",186);
        gotoxy(cf,l);printf("%c",186);

    }

    gotoxy(ci,li);printf("%c",201);
    gotoxy(ci,lf);printf("%c",200);
    gotoxy(cf,li);printf("%c",187);
    gotoxy(cf,lf);printf("%c",188);
}


void moldura(int ci, int cf, int li, int lf);






char forca[6][9]={{"+====h   "},
                {"y    y   "},
                {"y    o   "},
                {"y        "},
                {"y        "},
                {"p========"}};



char menu[13][98]={{"  pppppo pppppppo     pppppo ppo   ppopppppppopppo   ppoppppppppoppo   ppoppppppo  pppppo pppppppo"},
                 {" ppirrppoppirrrry    ppirrppoppu   ppuppirrrryppppo  pputrrppirryppu   ppuppirrppoppirrppoppirrrry"},
                 {" pppppppupppppppo    pppppppuppu   ppupppppo  ppippo ppu   ppu   ppu   ppuppppppiypppppppupppppppo"},
                 {" ppirrpputrrrrppu    ppirrpputppo ppiyppirry  pputppoppu   ppu   ppu   ppuppirrppoppirrpputrrrrppu"},
                 {" ppu  ppupppppppu    ppu  ppu tppppiy pppppppoppu tppppu   ppu   tppppppiyppu  ppuppu  ppupppppppu"},
                 {" try  trytrrrrrry    try  try  trrry  trrrrrrytry  trrry   try    trrrrry try  trytry  trytrrrrrry"},
                 {"                                                                                                  "},
                 {"                ppppppo pppppppo         ppo ppppppo ppppppo  ppppppo pppppppo                    "},
                 {"                ppirrppoppirrrry         ppuppirrrppoppirrppoppirrrry ppirrrry                    "},
                 {"                ppu  ppupppppo           ppuppu   ppuppppppiyppu  pppopppppo                      "},
                 {"                ppu  ppuppirry      pp   ppuppu   ppuppirrppoppu   ppuppirry                      "},
                 {"                ppppppiypppppppo    tpppppiytppppppiyppu  pputppppppiypppppppo                    "},
                 {"                trrrrry trrrrrry     trrrry  trrrrry try  try trrrrry trrrrrry                    "}};
void gotoxy(int x, int y){
    COORD c;
    c.X = x -1;
    c.Y = y -1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

int menuteste(char *palavra,char *dica,int i,int palavraaleatoria) {
    int pos=0, lin=22, col=38,cont=0;
    int tecla;
    do {
        Menu();
        gotoxy(col,lin-4); printf("   O jogo da Forca   ");
        gotoxy(col,lin-2); printf("+===================+");
        gotoxy(col,lin-1); printf("|                   |");
        gotoxy(col,lin);   printf("|      1palyers     |");
        gotoxy(col,lin+1); printf("|                   |");
        gotoxy(col,lin+2); printf("|      2palyers     |");
        gotoxy(col,lin+3); printf("|                   |");
        gotoxy(col,lin+4); printf("|      Musica/Stop  |");
        gotoxy(col,lin+5); printf("|                   |");
        gotoxy(col,lin+6); printf("+===================+");

        gotoxy(col+2,lin+pos); printf("-->");
        tecla=getch();
        Beep(10,2);
            switch(tecla) {
                case 80:
                    gotoxy(col-4,lin+pos); printf("   ");
                    if(pos<4) pos+=2;
                    break;
                case 72:
                    gotoxy(col-4,lin+pos); printf("   ");
                    if(pos>0) pos-=2;
                    break;

            }
            if(tecla==13){
                switch(pos){
                    case 0:tecla1(palavra,dica,i,palavraaleatoria);break;
                    case 2:tecla2(palavra,dica);break;
                    case 4:if(cont==0){PlaySound(0,0,0);cont=1;}else{PlaySound(TEXT("forca.wav"), NULL, SND_LOOP| SND_ASYNC);cont=0;}break;

                }
                if(pos==0||pos==2)
                break;
            }
    } while(1);
    return(pos);


}

char menu2[16][4]={{"     ___                           _         "},
{"    |_  |                         | |        "},
{"      | | ___   __ _  ___       __| | __ _   "},
{"      | |/ _ \ / _` |/ _ \     / _` |/ _` |  "},
{"  /\__/ / (_) | (_| | (_) |   | (_| | (_| |  "},
{"  \____/ \___/ \__, |\___/     \__,_|\__,_|  "},
{"                __/ |                        "},
{"               |___/                         "},
{"              __                             "},
{"             / _|                            "},
{"            | |_ ___  _ __ ___ __ _          "},
{"            |  _/ _ \| '__/ __/ _` |         "},
{"            | || (_) | | | (_| (_| |         "},
{"            |_| \___/|_|  \___\__,_|         "},
{"                                             "},
{"                                             "}};
char game[15][25]={{"ppppppppppppppppppppppppp"},
                   {"pp    pp   pp ppp p    pp"},
                   {"p ppppp ppp p  p  p ppppp"},
                   {"p pp  p ppp p p p p   ppp"},
                   {"p ppp p     p ppp p ppppp"},
                   {"p ppp p ppp p ppp p ppppp"},
                   {"pp   pp ppp p ppp p    pp"},
                   {"ppppppppppppppppppppppppp"},
                   {"pp   pp ppp p    pp   ppp"},
                   {"p ppp p ppp p ppppp pp pp"},
                   {"p ppp p ppp p   ppp pp pp"},
                   {"p ppp p ppp p ppppp   ppp"},
                   {"p ppp pp p pp ppppp pp pp"},
                   {"pp   pppp ppp    pp ppp p"},
                   {"ppppppppppppppppppppppppp"}};

char win[6][44]= {{"         _   _       __           _         "},
                   {"        (_) | |     /_/          (_)        "},
                   {"__   __  _  | |_    ___    _ __   _    __ _ "},
                   {"\\ \\ / / | | | __|  / _ \\  | '__| | |  / _` |"},
                   {" \\ V /  | | | |_  | (_) | | |    | | | (_| |"},
                   {"  \\_/   |_| \\___|  \\___/  |_|    |_|  \\__,_|"}};



void Menu(){
int l,c;
//moldura(91,110, 15, 34);
//scorebar (c);
for (l=0;l<13;l++){
    for(c=0;c<98;c++){
        gotoxy(2+c,5+l);
        switch(menu[l][c]){
            case'p' : printf("%c",219);break;
            case'o' : printf("%c",187);break;
            case'i' : printf("%c",201);break;
            case'u' : printf("%c",186);break;
            case'y' : printf("%c",188);break;
            case't' : printf("%c",200);break;
            case'r' : printf("%c",205);break;
            default:printf("%c",menu[l][c]);
        };
    }
     //gotoxy(72,31);printf("O Jogo Da Forca");
     //gotoxy(72,34);printf("--> 1) 1palyers");
    // gotoxy(72,36);printf("--> 2) 2palyers");
    /// gotoxy(55,32);printf("--> 3) Mute");
}}


void forcadesenha(int erro){
int l,c;
    switch (erro){
        case 1 :forca[3][5]='|';break;

        case 0 :forca[4][6]=' ';break;


        case 2 :forca[3][6]=')';break;


        case 3 :forca[3][4]='(';break;


        case 4 :forca[4][6]='\\';break;


        case 5 :forca[4][4]='/';break;
}
    for (l=0;l<6;l++){
        for(c=0;c<9;c++){
            gotoxy(4+c,3+l);
            switch(forca[l][c]){
            case'+' : printf("%c",201  );break;
            case'y' : printf("%c",186  );break;
            case'p' : printf("%c",202  );break;
            case'o' : printf("%c",184  );break;
            case'=' : printf("%c",205  );break;
            case'h' : printf("%c",187  );break;
            default:printf("%c",forca[l][c]);
            };
        }
        printf("\n");
    }
}
void gameover(){
int l,c;
system("mode con:cols=34 lines=20");
//moldura(91,110, 15, 34);
//scorebar (c);
for (l=0;l<15;l++){
    for(c=0;c<25;c++){
        gotoxy(5+c,3+l);
        switch(game[l][c]){
            case'p' : printf("%c",219);break;
            default:printf("%c",game[l][c]);
        };
    }
}}
int telaInicial(int tecla,char *palavra,char *dica,int i,int palavraaleatoria){

    do{
        system("color 08");
        moldura(1,101,2,30);



        tecla=menuteste(palavra,dica,i,palavraaleatoria);


        fflush(stdin);
  //     if(tecla=='3')
//        PlaySound(TEXT("NULL"));


        break;
    }while(1);
return(tecla);
}

void vencer(){
    int l,c;
    system("mode con:cols=48 lines=16");

    for (l=0;l<6;l++){
    for(c=0;c<44;c++){
        gotoxy(3+c,5+l);
        printf("%c",win[l][c]);
        }
    }

}

