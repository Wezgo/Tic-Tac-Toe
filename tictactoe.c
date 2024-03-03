#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define jumptoxy(x, y) printf("\033[%d;%dH",(x), (y))

int main(int argc, char const *argv[])
{
    srand(time(0));

    printf("-----------\nTic Tac Toe\n-----------\n");
    int spielmodus = 0;
    char spielfeld[4] [4] = {{32, 32, 32, 32},{32, 32, 32, 32},{32, 32, 32, 32},{32, 32, 32, 32}};
    int zaehler = 0;
    char spieler;
    int x = 0;
    int y = 0;
    printf("Welchen Modus wählen Sie:\n[1] Zwei Spieler\n[2] Computer\nModus = ");
    scanf("%d", &spielmodus);

    switch (spielmodus)
    {
    case 1:
    for (int gewonnen = 0; gewonnen == 0;)
    {
        if (zaehler%2 == 0)
        {
            spieler = 'X';
        }
        else
        {
            spieler = 'O';
        }

        for (int i = 0; i == 0;)
        {
            printf("%c = ", spieler);
            scanf("%d, %d", &x ,&y);

            if (spielfeld [x] [y] == 'X' || spielfeld [x] [y] == 'O')
            {
                printf("Feld ist schon besetzt.\n");
            }
            else
            {
                i++;
            }
        }
        
        spielfeld [x] [y] = spieler;
        printf("%c | %c | %c\n--+---+--\n%c | %c | %c\n--+---+--\n%c | %c | %c\n\n", spielfeld[1][1], spielfeld[1][2], spielfeld[1][3], spielfeld[2][1], spielfeld[2][2], spielfeld[2][3], spielfeld[3][1], spielfeld[3][2], spielfeld[3][3]);
        zaehler++;

        if(((spielfeld [1] [1] == 'X') && (spielfeld [1] [2] == 'X') && (spielfeld [1] [3] == 'X')) || (spielfeld [2] [1] =='X') && (spielfeld [2] [2] == 'X') && (spielfeld [2] [3] == 'X') || (spielfeld [3] [1] == 'X') && (spielfeld [3] [2] == 'X') && (spielfeld [3] [3] == 'X') || (spielfeld [1] [1] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [3] == 'X') || (spielfeld [1] [3] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [1] == 'X') || (spielfeld [1] [1] == 'X') && (spielfeld [2] [1] == 'X') && (spielfeld [3] [1] == 'X') || (spielfeld [1] [2] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [2] == 'X') || (spielfeld [1] [3] == 'X') && (spielfeld [2] [3] == 'X') && (spielfeld [3] [3] == 'X'))
        {
            gewonnen++;
            printf("Glückwunsch!\nSpieler 1 hat gewonnen\n");
        }

        if(((spielfeld [1] [1] == 'O') && (spielfeld [1] [2] == 'O') && (spielfeld [1] [3] == 'O')) || (spielfeld [2] [1] =='O') && (spielfeld [2] [2] == 'O') && (spielfeld [2] [3] == 'O') || (spielfeld [3] [1] == 'O') && (spielfeld [3] [2] == 'O') && (spielfeld [3] [3] == 'O') || (spielfeld [1] [1] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [3] == 'O') || (spielfeld [1] [3] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [1] == 'O') || (spielfeld [1] [1] == 'O') && (spielfeld [2] [1] == 'O') && (spielfeld [3] [1] == 'O') || (spielfeld [1] [2] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [2] == 'O') || (spielfeld [1] [3] == 'O') && (spielfeld [2] [3] == 'O') && (spielfeld [3] [3] == 'O'))
        {
            gewonnen ++;
            printf("Glückwunsch!\nSpieler 2 hat gewonnen\n");
        }

        if(zaehler == 9)
        {
            gewonnen++;
            printf("Unentschieden!\n");
        }
    }
    	
        break;
    
    case 2:

    for (int gewonnen = 0; gewonnen == 0;)
    {
        if (zaehler%2 == 0)
        {
            spieler = 'X';
        }
        else
        {
            spieler = 'O';
        }

        if(spieler == 'X')
        {
            for (int i = 0; i == 0;)
        {
            printf("X = ");
            scanf("%d, %d", &x ,&y);

            if (spielfeld [x] [y] == 'X' || spielfeld [x] [y] == 'O')
            {
                printf("Feld ist schon besetzt.\n");
            }
            else
            {
                i++;
            }
        }
        }
        
        if(spieler == 'O')
        {
            for (int i = 0; i == 0;)
            {
                x = rand() % 3;
                x++;

                y = rand() % 3;
                y++;

                if (spielfeld [x] [y] == 'X' || spielfeld [x] [y] == 'O')
                {
                    
                }
                else
                {
                    i++;
                }
            }
        }
        
        spielfeld [x] [y] = spieler;
        printf("%c | %c | %c\n--+---+--\n%c | %c | %c\n--+---+--\n%c | %c | %c\n\n", spielfeld[1][1], spielfeld[1][2], spielfeld[1][3], spielfeld[2][1], spielfeld[2][2], spielfeld[2][3], spielfeld[3][1], spielfeld[3][2], spielfeld[3][3]);
        zaehler++;

        if(((spielfeld [1] [1] == 'X') && (spielfeld [1] [2] == 'X') && (spielfeld [1] [3] == 'X')) || (spielfeld [2] [1] =='X') && (spielfeld [2] [2] == 'X') && (spielfeld [2] [3] == 'X') || (spielfeld [3] [1] == 'X') && (spielfeld [3] [2] == 'X') && (spielfeld [3] [3] == 'X') || (spielfeld [1] [1] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [3] == 'X') || (spielfeld [1] [3] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [1] == 'X') || (spielfeld [1] [1] == 'X') && (spielfeld [2] [1] == 'X') && (spielfeld [3] [1] == 'X') || (spielfeld [1] [2] == 'X') && (spielfeld [2] [2] == 'X') && (spielfeld [3] [2] == 'X') || (spielfeld [1] [3] == 'X') && (spielfeld [2] [3] == 'X') && (spielfeld [3] [3] == 'X'))
        {
            gewonnen++;
            printf("Glückwunsch!\nSpieler 1 hat gewonnen\n");
        }

        if(((spielfeld [1] [1] == 'O') && (spielfeld [1] [2] == 'O') && (spielfeld [1] [3] == 'O')) || (spielfeld [2] [1] =='O') && (spielfeld [2] [2] == 'O') && (spielfeld [2] [3] == 'O') || (spielfeld [3] [1] == 'O') && (spielfeld [3] [2] == 'O') && (spielfeld [3] [3] == 'O') || (spielfeld [1] [1] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [3] == 'O') || (spielfeld [1] [3] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [1] == 'O') || (spielfeld [1] [1] == 'O') && (spielfeld [2] [1] == 'O') && (spielfeld [3] [1] == 'O') || (spielfeld [1] [2] == 'O') && (spielfeld [2] [2] == 'O') && (spielfeld [3] [2] == 'O') || (spielfeld [1] [3] == 'O') && (spielfeld [2] [3] == 'O') && (spielfeld [3] [3] == 'O'))
        {
            gewonnen ++;
            printf("Glückwunsch!\nSpieler 2 hat gewonnen\n");
        }

        if(zaehler == 9)
        {
            gewonnen++;
            printf("Unentschieden!\n");
        }
    }
        break;
    
    default:printf("Ungültige Eingabe\n");
    }

    return 0;
}