#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>      

int main(int argc, char const *argv[]) {
    srand(time(0)); // Zufallszahlengenerator mit der aktuellen Zeit als Seed

    printf("-----------\nTic Tac Toe\n-----------\n"); // Gibt eine Trennlinie und den Spieltitel aus
    int spielmodus = 0; // Deklaration und Initialisierung einer Variablen für den Spielmodus
    char spielfeld[4][4] = {{32, 32, 32, 32}, {32, 32, 32, 32}, {32, 32, 32, 32}, {32, 32, 32, 32}}; // Deklaration und Initialisierung des Spielfelds mit Leerzeichen
    int zaehler = 0; // Deklaration und Initialisierung eines Zählers für die Anzahl der Züge
    char spieler; // Deklaration einer Variablen für den aktuellen Spieler
    int x = 0; // Deklaration und Initialisierung der x-Koordinate
    int y = 0; // Deklaration und Initialisierung der y-Koordinate
    printf("Welchen Modus wählen Sie:\n[1] Zwei Spieler\n[2] Computer\nModus = "); // Gibt die Optionen für den Spielmodus aus
    scanf("%d", &spielmodus); // Nimmt die Eingabe für den Spielmodus entgegen

    switch (spielmodus) { // Beginn einer Fallunterscheidung je nach gewähltem Spielmodus
    case 1: // Fall für Zwei-Spieler-Modus

        for (int gewonnen = 0; gewonnen == 0;) { // Schleife für den Zwei-Spieler-Modus, läuft bis das Spiel endet
            if (zaehler % 2 == 0) { // Überprüft, ob der Zug für Spieler X oder O ist, basierend auf der Anzahl der bisherigen Züge
                spieler = 'X'; // Setzt den aktuellen Spieler auf X
            } else {
                spieler = 'O'; // Setzt den aktuellen Spieler auf O
            }

            for (int i = 0; i == 0;) { // Schleife für die Eingabe der Koordinaten eines Zugs
                printf("%c = ", spieler); // Gibt den aktuellen Spieler aus
                scanf("%d, %d", &x, &y); // Nimmt die Eingabe der Koordinaten entgegen

                if (spielfeld[x][y] == 'X' || spielfeld[x][y] == 'O') { // Überprüft, ob das Feld bereits belegt ist
                    printf("Feld ist schon besetzt.\n"); // Gibt eine Meldung aus, dass das Feld bereits belegt ist
                } else {
                    i++; // Beendet die Schleife für die Koordinateneingabe, wenn das Feld frei ist
                }
            }

            spielfeld[x][y] = spieler; // Setzt auf das gewählte Feld den Spielerbuchstaben
            // Gibt das aktuelle Spielfeld aus
            printf("%c | %c | %c\n--+---+--\n%c | %c | %c\n--+---+--\n%c | %c | %c\n\n", spielfeld[1][1], spielfeld[1][2], spielfeld[1][3], spielfeld[2][1], spielfeld[2][2], spielfeld[2][3], spielfeld[3][1], spielfeld[3][2], spielfeld[3][3]);
            zaehler++; // Inkrementiert den Zähler für die Anzahl der Züge

            // Überprüft auf Gewinnbedingungen für Spieler X
            if (((spielfeld[1][1] == 'X') && (spielfeld[1][2] == 'X') && (spielfeld[1][3] == 'X')) || 
                ((spielfeld[2][1] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[2][3] == 'X')) || 
                ((spielfeld[3][1] == 'X') && (spielfeld[3][2] == 'X') && (spielfeld[3][3] == 'X')) || 
                ((spielfeld[1][1] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][3] == 'X')) || 
                ((spielfeld[1][3] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][1] == 'X')) || 
                ((spielfeld[1][1] == 'X') && (spielfeld[2][1] == 'X') && (spielfeld[3][1] == 'X')) || 
                ((spielfeld[1][2] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][2] == 'X')) || 
                ((spielfeld[1][3] == 'X') && (spielfeld[2][3] == 'X') && (spielfeld[3][3] == 'X'))) {
                gewonnen++; // Beendet die Spielrunde und markiert Spieler 1 als Gewinner
                printf("Glückwunsch!\nSpieler 1 hat gewonnen\n");
            }

            // Überprüft auf Gewinnbedingungen für Spieler O
            if (((spielfeld[1][1] == 'O') && (spielfeld[1][2] == 'O') && (spielfeld[1][3] == 'O')) || 
                ((spielfeld[2][1] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[2][3] == 'O')) || 
                ((spielfeld[3][1] == 'O') && (spielfeld[3][2] == 'O') && (spielfeld[3][3] == 'O')) || 
                ((spielfeld[1][1] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][3] == 'O')) || 
                ((spielfeld[1][3] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][1] == 'O')) || 
                ((spielfeld[1][1] == 'O') && (spielfeld[2][1] == 'O') && (spielfeld[3][1] == 'O')) || 
                ((spielfeld[1][2] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][2] == 'O')) || 
                ((spielfeld[1][3] == 'O') && (spielfeld[2][3] == 'O') && (spielfeld[3][3] == 'O'))) {
                gewonnen++; // Beendet die Spielrunde und markiert Spieler 2 als Gewinner
                printf("Glückwunsch!\nSpieler 2 hat gewonnen\n");
            }

            if (zaehler == 9) { // Überprüft, ob das Spiel unentschieden ist
                gewonnen++; // Beendet die Spielrunde und markiert das Spiel als unentschieden
                printf("Unentschieden!");
            }
        }

        break;

    case 2: // Fall für Einzelspieler-Modus gegen den Computer

        for (int gewonnen = 0; gewonnen == 0;) { // Schleife für den Einzelspieler-Modus, läuft bis das Spiel endet
            if (zaehler % 2 == 0) { // Überprüft, ob der Zug für Spieler X oder O ist, basierend auf der Anzahl der bisherigen Züge
                spieler = 'X'; // Setzt den aktuellen Spieler auf X
            } else {
                spieler = 'O'; // Setzt den aktuellen Spieler auf O
            }

            if (spieler == 'X') { // Wenn der Spieler X ist, wird die Eingabe vom Benutzer erwartet
                for (int i = 0; i == 0;) { // Schleife für die Eingabe der Koordinaten eines Zugs
                    printf("X = "); // Gibt den aktuellen Spieler aus
                    scanf("%d, %d", &x, &y); // Nimmt die Eingabe der Koordinaten entgegen

                    if (spielfeld[x][y] == 'X' || spielfeld[x][y] == 'O') { // Überprüft, ob das Feld bereits belegt ist
                        printf("Feld ist schon besetzt.\n"); // Gibt eine Meldung aus, dass das Feld bereits belegt ist
                    } else {
                        i++; // Beendet die Schleife für die Koordinateneingabe, wenn das Feld frei ist
                    }
                }
            }

            if (spieler == 'O') { // Wenn der Spieler O ist, wird der Zug vom Computer gemacht
                for (int i = 0; i == 0;) { // Schleife für die Berechnung eines gültigen Zugs des Computers
                    x = rand() % 3 + 1; // Generiert eine zufällige x-Koordinate
                    y = rand() % 3 + 1; // Generiert eine zufällige y-Koordinate

                    if (spielfeld[x][y] == 'X' || spielfeld[x][y] == 'O') { // Überprüft, ob das Feld bereits belegt ist
                        // Wenn das Feld schon besetzt ist, wird die Schleife wiederholt
                    } else {
                        i++; // Beendet die Schleife, wenn ein gültiger Zug gefunden wurde
                    }
                }
            }

            spielfeld[x][y] = spieler; // Setzt den Spielerbuchstaben auf das gewählte Feld
            // Gibt das aktuelle Spielfeld aus
            printf("%c | %c | %c\n--+---+--\n%c | %c | %c\n--+---+--\n%c | %c | %c\n\n", spielfeld[1][1], spielfeld[1][2], spielfeld[1][3], spielfeld[2][1], spielfeld[2][2], spielfeld[2][3], spielfeld[3][1], spielfeld[3][2], spielfeld[3][3]);
            zaehler++; // Inkrementiert den Zähler für die Anzahl der Züge

            // Überprüft auf Gewinnbedingungen für Spieler X
            if (((spielfeld[1][1] == 'X') && (spielfeld[1][2] == 'X') && (spielfeld[1][3] == 'X')) || 
                ((spielfeld[2][1] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[2][3] == 'X')) || 
                ((spielfeld[3][1] == 'X') && (spielfeld[3][2] == 'X') && (spielfeld[3][3] == 'X')) || 
                ((spielfeld[1][1] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][3] == 'X')) || 
                ((spielfeld[1][3] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][1] == 'X')) || 
                ((spielfeld[1][1] == 'X') && (spielfeld[2][1] == 'X') && (spielfeld[3][1] == 'X')) || 
                ((spielfeld[1][2] == 'X') && (spielfeld[2][2] == 'X') && (spielfeld[3][2] == 'X')) || 
                ((spielfeld[1][3] == 'X') && (spielfeld[2][3] == 'X') && (spielfeld[3][3] == 'X'))) {
                gewonnen++; // Beendet die Spielrunde und markiert Spieler 1 als Gewinner
                printf("Glückwunsch!\nSpieler 1 hat gewonnen\n");
            }

            // Überprüft auf Gewinnbedingungen für Spieler O
            if (((spielfeld[1][1] == 'O') && (spielfeld[1][2] == 'O') && (spielfeld[1][3] == 'O')) || 
                ((spielfeld[2][1] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[2][3] == 'O')) || 
                ((spielfeld[3][1] == 'O') && (spielfeld[3][2] == 'O') && (spielfeld[3][3] == 'O')) || 
                ((spielfeld[1][1] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][3] == 'O')) || 
                ((spielfeld[1][3] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][1] == 'O')) || 
                ((spielfeld[1][1] == 'O') && (spielfeld[2][1] == 'O') && (spielfeld[3][1] == 'O')) || 
                ((spielfeld[1][2] == 'O') && (spielfeld[2][2] == 'O') && (spielfeld[3][2] == 'O')) || 
                ((spielfeld[1][3] == 'O') && (spielfeld[2][3] == 'O') && (spielfeld[3][3] == 'O'))) {
                gewonnen++; // Beendet die Spielrunde und markiert den Computer als Gewinner
                printf("Glückwunsch!\nSpieler 2 hat gewonnen\n");
            }

            if (zaehler == 9) { // Überprüft, ob das Spiel unentschieden ist
                gewonnen++; // Beendet die Spielrunde und markiert das Spiel als unentschieden
                printf("Unentschieden!");
            }
        }

        break;

    default: // Falls eine ungültige Eingabe für den Spielmodus erfolgt ist
        printf("Ungültige Eingabe\n"); // Gibt eine Fehlermeldung aus
        break;
    }
    return 0; // Beendet das Programm
}
