//Jakubko prechádza cez les trasou, ktorú ste mu vyznačili ... lenže v húštinách sa niečo hýbe... Jakubko včera vynašiel prístroj na extrakciu bubliniek z hydrofóbnych roztokov a má preto dôvodné podozrenie, že ho prišli navštíviť kamaráti z inej galaxie, obáva sa únosu. Pomôžte mu strategicky analyzovať les, a objaviť v ňom kritické body, cez ktoré musí nutne prejsť bez ohľadu na trasu prechodu, ktorú si zvolí. Na týchto miestach chce byť Jakubko obzvlášť obozretný. Tmavý les je tvaru dvojrozmernej mriežky, Jakubko vstúpil do lesa vľavo hore, a potrebuje sa dostať do východu vpravo dole. Iné východy z lesa nie sú, v lese sa pohybujú mimozemšťania, ktorí sa pokúšajú Jakubka kontaktovať, on nemá záujem o takéto sociálne kontakty.
//
//Pomôžte Jakubkovi nájsť všetky kritické políčka (lesné cestičky) cez ktoré musí nutne prejsť bez ohľadu na zvolenú trasu.
//
//Vstup: Štandardný vstup obsahuje mapu lesa -- dvojrozmernú maticu znakov bodka (.) a mriežka (#). Bodka predstavuje lesnú cestičku. Mriežka predstavuje húštinu, cez ktorú sa Jakubko nemôže dostať. Mapa lesa môže byť veľká najviac 1000 riadkov a 1000 stĺpcov.
//
//Výstup: Na štandardný výstup vypíšte mapu lesa s vyznačenými kritickými miestami -- políčkami cez ktoré musí nutne prejsť bez ohľadu na zvolenú trasu prechodu z ľavého horného vchodu do pravého dolného východu. Kritické miesta označte výkričníkom (znak !).
//
//Ukážka vstupu:
//#.###############
//#...#...........#
//#.###.#####.#.#.#
//#...........#...#
//###############.#
//Výstup pre ukážkový vstup:
//#!###############
//#!..#......!!!..#
//#!###.#####.#.#.#
//#!!!!!......#..!#
//###############!#


// uloha8-1.c -- Jozef Varga, 7.11.2017 14:13

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char mapa[1000][1000];
char mapa2[1000][1000];
char mapa3[1000][1000];
int pomoc = 0;
void hladaj_cestu(int x, int y, int a_x, int a_y){
    
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


void hladaj_cestu2(int x, int y, int a_x, int a_y){
    
    if(x==a_y && y==a_x){
        pomoc = 1;
        return;}
    if(mapa2[a_x][a_y+1] != '#' && mapa2[a_x][a_y+1] != 'x'){
        mapa2[a_x][a_y+1] = 'x';
        hladaj_cestu2(x, y, a_x, a_y+1);
        if(pomoc == 1)return;
    }
    if(mapa2[a_x+1][a_y] != '#' && mapa2[a_x+1][a_y] != 'x'){
        mapa2[a_x+1][a_y] = 'x';
        hladaj_cestu2(x, y, a_x+1, a_y);
        if(pomoc == 1)return;
    }
    if(mapa2[a_x][a_y-1] != '#' && mapa2[a_x][a_y-1] != 'x'){
        mapa2[a_x][a_y-1] = 'x';
        hladaj_cestu2(x, y, a_x, a_y-1);
        if(pomoc == 1)return;
    }
    if(mapa2[a_x-1][a_y] != '#' && mapa2[a_x-1][a_y] != 'x'){
        mapa2[a_x-1][a_y] = 'x';
        hladaj_cestu2(x, y, a_x-1, a_y);
        if(pomoc == 1)return;
    }
    if(pomoc == 1)return;
    mapa2[a_x][a_y] = '.';
    return;
}

void hladaj_cestu3(int x, int y, int a_x, int a_y){
    
    if(x==a_y && y==a_x){
        pomoc = 1;
        return;}
    if(mapa3[a_x+1][a_y] != '#' && mapa3[a_x+1][a_y] != 'x'){
        mapa3[a_x+1][a_y] = 'x';
        hladaj_cestu3(x, y, a_x+1, a_y);
        if(pomoc == 1)return;
    }
    if(mapa3[a_x][a_y+1] != '#' && mapa3[a_x][a_y+1] != 'x'){
        mapa3[a_x][a_y+1] = 'x';
        hladaj_cestu3(x, y, a_x, a_y+1);
        if(pomoc == 1)return;
    }
    if(mapa3[a_x-1][a_y] != '#' && mapa3[a_x-1][a_y] != 'x'){
        mapa3[a_x-1][a_y] = 'x';
        hladaj_cestu3(x, y, a_x-1, a_y);
        if(pomoc == 1)return;
    }
    if(mapa3[a_x][a_y-1] != '#' && mapa3[a_x][a_y-1] != 'x'){
        mapa3[a_x][a_y-1] = 'x';
        hladaj_cestu3(x, y, a_x, a_y-1);
        if(pomoc == 1)return;
    }
    if(pomoc == 1)return;
    mapa3[a_x][a_y] = '.';
    return;
}


int main()
{
    // sem napis svoje riesenie
    int i = 0;
    while(scanf("%s",mapa[i]) > 0){
        strcpy(mapa2[i], mapa[i]);
        strcpy(mapa3[i], mapa[i]);
        i++;
    }
    int x = strlen(mapa[0]);
    int y = i;
    mapa[0][1] = '*';
    hladaj_cestu(x-2, y-1, 0, 1);
    
    pomoc = 0;
    mapa2[0][1] = 'x';
    hladaj_cestu2(x-2, y-1, 0, 1);
    
    pomoc = 0;
    mapa3[0][1] = 'x';
    hladaj_cestu3(x-2, y-1, 0, 1);
    
    for(int j=0;j<x;j++){
        for(int i = 0;i<y;i++){
            if(mapa[i][j] == '*' && mapa2[i][j] == 'x' && mapa3[i][j] == 'x')mapa[i][j] = '!';
            if(mapa[i][j] == '*')mapa[i][j] = '.';
        }
    }
    for(i=0;i<y;i++){
        printf("%s\n",mapa[i]);
    }
    
    
    return 0;
}
