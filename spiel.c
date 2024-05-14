#include "spiel.h"

void clearInputBuffer3() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void generiereZufaelligeBinaerzahl(char binaer[], int laenge) {
  for (int i = 0; i < laenge; i++)
    binaer[i] = (rand() % 2 == 0) ? '0' : '1';
  binaer[laenge] = '\0';
}

int binaerZuDezimal(char binaer[]) {
  int dezimal = 0;
  int laenge = strlen(binaer);
  int basis = 1;
  for (int i = laenge - 1; i >= 0; i--) {
    if (binaer[i] == '1')
      dezimal += basis;
    basis = basis * 2;
  }
  return dezimal;
}

    bool fragen_nochmal_spielen() {
    printf("Möchten Sie noch einmal spielen? (j/n) ");
    char antwort = getchar();
    clearInputBuffer3();
    return antwort == 'j';
    }

void speichere_spiel_ergebnis(int richtig, int gesamt) {
FILE *fp;
fp = fopen("spiel_ergebnis.txt", "a");
if (fp == NULL) {
printf("Datei konnte nicht geöffnet werden.\n");
return;
}
fprintf(fp, "Sie haben %d von %d richtig beantwortet.\n", richtig, gesamt);
fclose(fp);
}

void dezimal_zu_binaer(int zufallszahl, int *binaer) {
    int rest, basis = 1;
    *binaer = 0;
    while (zufallszahl > 0) {
        rest = zufallszahl % 2;
        zufallszahl /= 2;
        *binaer += rest * basis;
        basis *= 10;
    }
}

void spiel_binaer_zu_dezimal () { //funkioniert
    srand(time(NULL));
    int richtig = 0;
    int gesamt = 0;
    bool nochmalSpielen = true;
    while (nochmalSpielen) {
        char binaer[9];
        int dezimal;
        generiereZufaelligeBinaerzahl(binaer, 8);
        printf("Geben Sie die Dezimalzahl zu folgender Binärzahl ein: %s\n", binaer);
        scanf("%d", &dezimal);
        clearInputBuffer3();
        if (dezimal == binaerZuDezimal(binaer)) {
            printf("Richtig!\n");
            richtig++;
        } else {
            printf("Falsch. Die richtige Antwort ist: %d\n", binaerZuDezimal(binaer));
        }
        gesamt++;
        
        nochmalSpielen = fragen_nochmal_spielen();
    }
    
    printf("Sie haben %d von %d richtig beantwortet.\n", richtig, gesamt);
    speichere_spiel_ergebnis(richtig, gesamt);
    
}


void spielen_dezimal_zu_binaer()  { //funktioniert
    int richtige_antworten = 0, gesamt_spiele = 0;
    char weiterspielen = 'j';
    while (weiterspielen == 'j') {
        int zufallszahl, benutzereingabe, binaer;
        
        srand(time(NULL));
        zufallszahl = rand() % 100 + 1;
        
        printf("Wie lautet die Binärzahl von %d?\n", zufallszahl);
        scanf("%d", &benutzereingabe);
        
        dezimal_zu_binaer(zufallszahl, &binaer);
        
        if (binaer == benutzereingabe) {
            printf("Korrekt!\n");
            richtige_antworten +=1;
        } else {
            printf("Falsch. Die richtige Binärzahl ist: %d\n", binaer);
        }
        gesamt_spiele +=1;
        clearInputBuffer3();
        printf("Wollen sie weiterspielen(j/n)?\n");
        scanf("%c", &weiterspielen);
        
        if (weiterspielen != 'j') {
            break;
        }
    }
    berechne_punktestand1(richtige_antworten, gesamt_spiele);
}
void berechne_punktestand1(int richtige_antworten, int gesamt_spiele) {
printf("Sie haben %d von %d Spielen richtig beantwortet.\n", richtige_antworten, gesamt_spiele);
}

// Spiel 3:
void spiele_bin_zu_hex() {
    int richtige_antworten = 0, gesamt_spiele = 0; int binaer1;
    bool nochmalSpielen = true;
    while (nochmalSpielen) {
        srand(time(NULL));
        int zufallszahl = rand() % 256; // Zufällige 8-Bit Zahl
        printf("Bitte geben Sie die Hexadezimalrepräsentation dieser binären Zahl ein: %d\n", zufallszahl);
        
        int eingabe;
        scanf("%x", &eingabe); // Lese Hex-Wert ein
        
        if (eingabe == zufallszahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Hexadezimalrepräsentation ist: %x\n", zufallszahl);
        }
        gesamt_spiele +=1;
        clearInputBuffer3();
        nochmalSpielen = fragen_nochmal_spielen();
    }
    berechne_punktestand (richtige_antworten, gesamt_spiele);
}

void berechne_punktestand(int richtige_antworten, int gesamt_spiele) {
    printf("sie haben %d von %d Spielen richtig beantwortet", richtige_antworten, gesamt_spiele);
}

void spiele_okt_zu_dez() { //betrifft
    int richtige_antworten = 0, gesamt_spiele = 0;
    bool nochmalSpielen = true;
    while (nochmalSpielen) {
        srand(time(NULL));
        int zufallszahl = rand() % 512; // Zufällige 9-Bit Oktalzahl
        printf("Bitte geben Sie die Dezimalrepräsentation dieser Oktalzahl ein: %o\n", zufallszahl);

        int eingabe;
        scanf("%d", &eingabe); // Lese Dezimalwert ein
        
        if (eingabe == zufallszahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Dezimalrepräsentation ist: %d\n", zufallszahl);
        }
        gesamt_spiele +=1;
        clearInputBuffer3();
        nochmalSpielen = fragen_nochmal_spielen();
    }
    berechne_punktestand (richtige_antworten, gesamt_spiele);
}

void spiele_dez_zu_okt() { //betrifft
    int weiter = 1, richtige_antworten = 0, gesamt_spiele = 0;
    while (weiter == 1) {
        srand(time(NULL));
        int zufallszahl = rand() % 512; // Zufällige 9-Bit Dezimalzahl
        printf("Bitte geben Sie die Oktalrepräsentation dieser Dezimalzahl ein: %d\n", zufallszahl);

        int eingabe;
        scanf("%o", &eingabe); // Lese Oktalwert ein
        
        if (eingabe == zufallszahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Oktalrepräsentation ist: %o\n", zufallszahl);
        }
        gesamt_spiele +=1;
        printf("Möchten Sie nochmal spielen? (1 = ja, 0 = nein)\n");
        scanf("%d", &weiter);
    }
    berechne_punktestand (richtige_antworten, gesamt_spiele);
}

void spiele_bin_zu_okt() { //betrifft
    int weiter = 1, richtige_antworten = 0, gesamt_spiele = 0;
    while (weiter == 1) {
        srand(time(NULL));
        int zufallszahl = rand() % 512; // Zufällige 9-Bit binäre Zahl
        printf("Bitte geben Sie die Oktalrepräsentation dieser binären Zahl ein: %d\n", zufallszahl);
        int eingabe;
        scanf("%o", &eingabe); // Lese Oktal-Wert ein
        
        if (eingabe == zufallszahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Oktalrepräsentation ist: %o\n", zufallszahl);
        }
        gesamt_spiele +=1;
        printf("Möchten Sie nochmal spielen? (1 = ja, 0 = nein)\n");
        scanf("%d", &weiter);
    }
    berechne_punktestand(richtige_antworten, gesamt_spiele);
}

void spiele_okt_zu_bin() { //betrifft
    int weiter = 1, richtige_antworten = 0, gesamt_spiele = 0;
    while (weiter == 1) {
        srand(time(NULL));
        int zufallszahl = rand() % 512; // Zufällige 9-Bit Oktalzahl
        printf("Bitte geben Sie die Binärrepräsentation dieser Oktalzahl ein: %o\n", zufallszahl);
        int eingabe;
        scanf("%d", &eingabe); // Lese Binärwert ein
        
        int binaer_zahl = 0, i = 1, rest;
        while (zufallszahl != 0) {
            rest = zufallszahl % 2;
            zufallszahl /= 2;
            binaer_zahl += rest * i;
            i *= 10;
        }
        
        if (eingabe == binaer_zahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Binärrepräsentation ist: %d\n", binaer_zahl);
        }
        gesamt_spiele +=1;
        printf("Möchten Sie nochmal spielen? (1 = ja, 0 = nein)\n");
        scanf("%d", &weiter);
    }
    berechne_punktestand (richtige_antworten, gesamt_spiele);
}

void spiele_okt_zu_hex() { //betrifft
    int weiter = 1, richtige_antworten = 0, gesamt_spiele = 0;
    while (weiter == 1) {
        srand(time(NULL));
        int zufallszahl = rand() % 512; // Zufällige 9-Bit Oktalzahl
        printf("Bitte geben Sie die Hexadezimalrepräsentation dieser Oktalzahl ein: %o\n", zufallszahl);
        int eingabe;
        scanf("%d", &eingabe); // Lese Binärwert ein
        
        int binaer_zahl = 0, i = 1, rest;
        while (zufallszahl != 0) {
            rest = zufallszahl % 2;
            zufallszahl /= 2;
            binaer_zahl += rest * i;
            i *= 10;
        }
        
        if (eingabe == binaer_zahl) {
            richtige_antworten +=1;
            printf("Richtig!\n");
        } else {
            printf("Falsch. Die korrekte Binärrepräsentation ist: %d\n", binaer_zahl);
        }
        gesamt_spiele +=1;
        printf("Möchten Sie nochmal spielen? (1 = ja, 0 = nein)\n");
        scanf("%d", &weiter);
    }
    berechne_punktestand (richtige_antworten, gesamt_spiele);
}

void alle_Spiele () {
    int eingabe;
    printf("was wollen sie spielen/berechnen ?: binär zu Hex (1), binär zu dez (2), dez zu binär (3), okt zu dez (4), bin zu okt(5),  okt zu bin(6), okt zu hex(7),  dez zu okt (8)");
    scanf("%d", &eingabe);
    switch (eingabe) {
        case 1:
            spiele_bin_zu_hex();
            break;
        case 2:
            spiel_binaer_zu_dezimal();
            break;
        case 3:
            spielen_dezimal_zu_binaer();
            break;
        case 4:
            spiele_okt_zu_dez();
            break;
        case 5:
            spiele_bin_zu_okt();
            break;
        case 6:
            spiele_okt_zu_bin();
            break;
        case 7:
            spiele_okt_zu_hex();
            break;
        case 8:
            spiele_dez_zu_okt();
            break;
        default:
            printf("Ungültige Eingabe. Bitte geben Sie 1, 2, 3, 4, 5, 6 oder 7 ein.");
            break;
    }
}

