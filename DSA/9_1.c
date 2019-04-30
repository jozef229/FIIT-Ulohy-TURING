//Jakubko stále niečo vymýšľa... rozhodol sa, že rozbehne podnikanie, a kedže samému sa podniká ťažko, prehovoril svojho bračeka Jána Rastislava, že budú roznášať darčeky. Podnikateľský plán je založený na nezabudnuteľnom zážitku pri preberaní darčeku. Darčeky sa preto starostliovo zabalia a roznášajú po jednom. Pomôžte teraz bratom naplánovať roznášanie darčekov tak, aby roznos bol čím skôr dokončený.
//
//Mesto, v ktorom darčeky roznášajú, je súvislý graf, vrcholy sú domy a hrany sú ulice medzi domami, každá hrana má dĺžku koľko trvá prechod touto hranou ľubovoľným smerom. Podnikatelia majú svoju centrálu vo vrchole 1 a roznášajú darčeky do ostatných vrcholov. Najskôr vždy pobalia darčeky a potom ich začnú roznášať. Sú nato dvaja, v každom okamihu môže mať každý z nich v rukách najviac jeden darček a je na ceste z centrály do miesta určenia alebo sa vracia na centrálu (po ďalší darček). Prácu si rozdelia tak, aby bola čo najskôr hotová; pracovné podmienky sú ťažké, roznášajú bez nároku na oddych. Pomôžte bratom a zistite, za aký najkratší čas budú všetky darčeky roznesené a obaja sa vrátia na centrálu k spoločnému obedu.
//
//Vstup: Štandardný vstup obsahuje zadaný graf -- počet domov (vrcholov grafu) N < 100 a počet ulíc (hrán grafu) M < 5000. Nasleduje M trojíc A B D, ktoré opisujú cestu medzi vrcholmi A a B, pričom dĺžka koľko trvá prechod po hrane je D < 50 časových jednotiek. Nasleduje počet darčekov na roznos K < 100 a K čísel domov do ktorých treba pojednom poroznášať darčeky.
//
//Výstup: Na štandardný výstup vypíšte najkratší čas za ktorý dokážu darčeky po jednom rozniesť a vrátiť sa naspäť do centrály.
//
//Ukážka vstupu:
//5 6
//2 1 5
//3 4 5
//5 3 10
//1 3 20
//3 2 5
//4 5 10
//5
//2
//3
//3
//4
//5
//Výstup pre ukážkový vstup:
//60
//Vysvetlenie: jeden bude roznesie do 2, 3 a 4, druhý roznesie do 3 a 5

// uloha9-1.c -- Jozef Varga, 13.11.2017 10:36


#include<stdio.h>
int main()
{
    
    int x = 0,y = 0;
    int a,b,c;
    scanf("%d",&x);
    scanf("%d",&y);
    int graf[x][x];
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            graf[i][j] = 99999;
            graf[i][i] = 0;
        }
    }
    for(int i = 0; i<y;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        graf[a-1][b-1] = c;
        graf[b-1][a-1] = c;
    }
    
    for(int i = 0; i<x; i++){
        //printf("\n");
        for(int j = 0; j<x; j++){
            //if(graf[i][j] == 99999)printf("IN\t");
            //else printf("%d\t",graf[i][j]);
        }
    }
    //printf("\n");
    int upravena[x][x], i, j, k;
    for (i = 0; i < x; i++)
        for (j = 0; j < x; j++)
            upravena[i][j] = graf[i][j];
    for (k = 0; k < x; k++)
    {
        for (i = 0; i < x; i++)
        {
            for (j = 0; j < x; j++)
            {
                if ((upravena[i][k] + upravena[k][j]) < upravena[i][j]){
                    upravena[i][j] = upravena[i][k] + upravena[k][j];
                }
            }
        }
    }
    for(int i = 0; i<x; i++){
        //printf("\n");
        for(int j = 0; j<x; j++){
            //if(dist[i][j] == 99999)printf("IN\t");
            //else printf("%d\t",dist[i][j]);
        }
    }
    //printf("\n");
    scanf("%d",&a);
    int prvy = 0;
    int druhy = 0;
    for(int i = 0;i<a;i++){
        scanf("%d",&b);
        if(prvy>=druhy){
            prvy += upravena[0][b-1];
        }else druhy += upravena[0][b-1];
    }
    if(prvy%2 != 0)prvy +=1;
    if(prvy>=druhy)printf("%d\n",prvy);
    else printf("%d\n",druhy);
    
    
    return 0;
}
