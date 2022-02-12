#include <iostream>

using namespace std;
#define BYTE 8
struct carattere {
    char binario[BYTE + 1];
    carattere *succ;
};
typedef carattere *lista;

// Inserisce il carattere “daIns” in coda alla lista “stringa”.
void inserimentoInCoda(lista &stringa, carattere daIns) {
    lista p, q;
    for (q = stringa; q != 0; q = q->succ) p = q;
    q = new carattere;
    *q = daIns;
    q->succ = 0;
    if (stringa == 0) stringa = q;
    else p->succ = q;
}

// Rimuove tutti gli elementi della lista “stringa”.
void svuotaLista(lista &stringa) {
    while (stringa != 0) {
        lista q = stringa;
        stringa = stringa->succ;
        delete q;
    }
}

/* Stampa a schermo gli elementi della lista “stringa” come nell'esempio di
esecuzione. */
void stampaLista(lista stringa) {
    while (stringa != 0) {
        cout << stringa->binario << ' ';
        stringa = stringa->succ;
    }
    cout << endl;
}

// Restituisce il valore di “n” elevato alla potenza “esponente”.
int potenza(int n, unsigned esponente) {
    int pot;
    for (pot = 1; esponente > 0; esponente--) pot *= n;
    /* Senza for
     * pot = 1;
     * while (esponente-- > 0) pot *= n;
     */
    return pot;
}

/* Esegue la conversione in codice ASCII (binario) del carattere “input”,
rappresentandola come una sequenza di caratteri “0” e “1” da inserire nella
stringa “convertito”. */
void conversioneBinaria(char *convertito, char input) {
    for (int i = 7; i >= 0; i--) {
        int pow2 = potenza(2, i);
        /* Bitwise AND operator.
         *
         * Prende i binari dei due operandi e li confronta bit per bit.
         * Es.
         * 8 = 1 0 0 0
         * 7 = 0 1 1 1
         *
         * Risultato 0.
         *
         */
        if (input & pow2) convertito[7 - i] = '1';
        else convertito[7 - i] = '0';
    }
    convertito[8] = '\0';
}

/* Programma principale: chiama le funzioni precedenti e gestisce la
continuazione o la terminazione del programma. */
int main() {

    char input = 0;
    lista str = 0;
    carattere ins;
    ins.succ = 0;

    bool run;
    bool bad;

    do {
        cout << "Scrivere i caratteri da convertire in binario:" << endl;
        while (input != '\n') {
            cin.get(input);
            conversioneBinaria(ins.binario, input);
            inserimentoInCoda(str, ins);
        }
        cout << "Conversione: " << endl;
        stampaLista(str);
        svuotaLista(str);
        do {
            cout << "Vuoi continuare? s/n:" << endl;
            cin >> input;
            switch (input) {
                case 's':
                case 'S':
                    run = true;
                    bad = false;
                    break;

                case 'n':
                case 'N':
                    run = false;
                    bad = false;
                    break;

                default:
                    bad = true;
                    cout << "Usa solo caratteri consentiti!" << endl;
            }
        } while (bad);
        cin.ignore();
    } while (run);
    return 0;
}
