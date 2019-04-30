//Jakubko sa ocitol v tmavom lese. Obzerá sa naokolo, vidí samé húštiny a tmavé chodbičky -- lesné cestičky. Pomôžte mu nájsť cestu von. Tmavý les je tvaru dvojrozmernej mriežky znakov, Jakubko vstúpil do lesa vľavo hore, a potrebuje sa dostať do východu vpravo dole. Iné východy z lesa nie sú... zazdalo sa mu, že sa v tom lese niečo hýbe...
//
//Pomôžte Jakubkovi nájsť cestu z lesa von.
//
//Vstup: Štandardný vstup obsahuje mapu lesa -- dvojrozmernú maticu znakov bodka (.) a mriežka (#). Bodka predstavuje lesnú cestičku. Mriežka predstavuje húštinu, cez ktorú sa Jakubko nemôže dostať. Mapa lesa môže byť veľká najviac 1000 riadkov a 1000 stĺpcov.
//
//Výstup: Na štandardný výstup vypíšte mapu lesa s vyznačenou trasou prechodu z ľavého horného vchodu do pravého dolného východu. Trasu vyznačte hviezdičkami (znak *).
//
//Ukážka vstupu:
//#.###############
//#...#...........#
//#.###.#####.#.###
//#.........#.#...#
//###############.#
//Výstup pre ukážkový vstup:
//#*###############
//#*..#*********..#
//#*###*#####.#*###
//#*****....#.#***#
//###############*#

// uloha8-1.c -- Jozef Varga, 7.11.2017 14:13

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char mapa[1000][1000];
int pomoc = 0;
void hladaj_cestu(int x, int y, int a_x, int a_y){
    //printf("\n");
    // for(int i=0;i<5;i++){
    //     printf("%s\n",mapa[i]);
    //}
    if(x==a_y && y==a_x){
        pomoc = 1;
        return;}
    if(mapa[a_x+1][a_y] != '#' && mapa[a_x+1][a_y] != '*'){
        mapa[a_x+1][a_y] = '*';
        hladaj_cestu(x, y, a_x+1, a_y);
        if(pomoc == 1)return;
    }
    if(mapa[a_x-1][a_y] != '#' && mapa[a_x-1][a_y] != '*'){
        mapa[a_x-1][a_y] = '*';
        hladaj_cestu(x, y, a_x-1, a_y);
        if(pomoc == 1)return;
    }
    if(mapa[a_x][a_y+1] != '#' && mapa[a_x][a_y+1] != '*'){
        mapa[a_x][a_y+1] = '*';
        hladaj_cestu(x, y, a_x, a_y+1);
        if(pomoc == 1)return;
    }
    if(mapa[a_x][a_y-1] != '#' && mapa[a_x][a_y-1] != '*'){
        mapa[a_x][a_y-1] = '*';
        hladaj_cestu(x, y, a_x, a_y-1);
        if(pomoc == 1)return;
    }
    if(pomoc == 1)return;
    mapa[a_x][a_y] = '.';
    return;
}

int main()
{
    // sem napis svoje riesenie
    int i = 0;
    while(scanf("%s",mapa[i]) > 0){
        i++;
        //if(i==5)break;
    }
    int x = strlen(mapa[0]);
    int y = i;
    mapa[0][1] = '*';
    hladaj_cestu(x-2, y-1, 0, 1);
    for(i=0;i<y;i++){
        printf("%s\n",mapa[i]);
    }
    
    
    
    return 0;
}
