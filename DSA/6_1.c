//Jakubko s Helenkou stavali veže z drevených kociek. Kocky stavali na dlhom chodníku, ktorý si možno predstaviť ako jednorozmerné pole. Vždy na i-tu pozíciu Helenka doložila niekoľko kociek a zvýšila tým vežu z kociek, ktorá na i-tom mieste stála. Na začiatok neboli na chodníku iné kocky. Jakubko mal inú dôležitú úlohu: vždy keď prišiel nejaký kamarát a zaujímalo ho koľko kociek je vo vežiach, ktoré stoja medzi dvoma význačnými bodmi (resp. od i-teho miesta ďalej dĺžky d), tak to musel rýchlo spočítať. Občas sa stalo, že nejaké zvieratko alebo neposlušný vetrík kocky z nejakého miesta aj zhodilo. Vašou úlohou je napísať algoritmus, ktorý by Jakubkovi pomohol zvládať nával zvedavých detí a rýchlo odpovedať na ich požiadavky.
//
//Štandardný vstup obsahuje niekoľko riadkov, na každom z nich je uvedená operácia:
//
//inc i k -- zvýšenie veže na i-tom mieste o k kociek (Helenka doložila kocky)
//dec i k -- zníženie veže na i-tom mieste o k kociek (vetrík sfúkol kocky)
//get i k -- otázka zvedavého kamaráta na počet kociek od i-teho miesta ďalej k kociek (až po miesto i+k vrátane)
//Hodnoty pozícií na vstupe budú od 0 do 100 000. Počet kociek je možné reprezentovať celým číslom int. Na štandardný výstup pre každú operáciu get vypíšte jedno číslo -- koľko kociek je v požadovanom intervale na chodníku.
//Poznámka: Vaše riešenie musí byť dostatočne efektívne, aby zbehlo v časovom limite.
//
//Ukážka vstupu:
//inc 10 5
//inc 15 3
//inc 8 7
//get 0 20
//get 10 5
//get 11 5
//get 10 4
//dec 15 2
//get 6 10
//get 6 5
//Výstup pre ukážkový vstup:
//15
//8
//3
//5
//13
//12


// uloha6-1.c -- Jozef Varga, 4.11.2017 16:28

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pridaj(int *pole, int k, int i){
    for(;k<100003;k = k + (k&(-k))){
        pole[k] = pole[k] + i;
    }
}

int interval(int *pole, int i){
    int pocet = 0;
    for(;i>0;i=i-(i&(-i))){
        pocet = pocet + pole[i];
    }
    return pocet;
}




int main()
{
    int i,k,pole[100002];
    char co[3];
    memset(pole, 0, 100002);
    while(scanf("%s",co)>0){
        scanf("%d",&k);
        scanf("%d",&i);
        switch (co[0]){
            case 'i':{
                pridaj(pole,k,i);
            };break;
            case 'g':{
                printf("%d\n",interval(pole,k+i) - interval(pole, k-1));
            };break;
            case 'd':{
                i = -i;
                // printf("a");
                pridaj(pole,k,i);
                // printf("b");
            };break;
        }
    }
    // sem napis svoje riesenie
    
    return 0;
}

