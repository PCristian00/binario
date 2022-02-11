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

// 3 Punti
}

// Rimuove tutti gli elementi della lista “stringa”.
void svuotaLista(lista &stringa) {

    while (stringa != 0) {
        lista q = stringa;
        stringa = stringa->succ;
        delete q;
    }
// 3 Punti
}

/* Stampa a schermo gli elementi della lista “stringa” come nell'esempio di
esecuzione. */
void stampaLista(lista stringa) {
    //int i=0;
    lista p;
    while (stringa != 0) {
        cout << stringa->binario << ' ';
        stringa = stringa->succ;
    }
    cout << endl;
    //for (p = stringa; p != 0; p = p->succ) cout << p->binario << '\t';

// 2 Punti
}

// Restituisce il valore di “n” elevato alla potenza “esponente”.
int potenza(int n, unsigned esponente) {
    int base = n;
    for (int i = 1; i < esponente; i++) {
        //cout<<n<<" * "<<base<<" = ";
        n *= base;
        //cout<<n<<endl;
    }
    return n;
// 2 Punti
}

/* Esegue la conversione in codice ASCII (binario) del carattere “input”,
rappresentandola come una sequenza di caratteri “0” e “1” da inserire nella
stringa “convertito”. */
void conversioneBinaria(char *convertito, char input) {
// 4 Punti
}

/* Programma principale: chiama le funzioni precedenti e gestisce la
continuazione o la terminazione del programma. */
int main() {

    /*
    int n,esp;
    cin>>n>>esp;
    cout<<potenza(n,esp);
     */


    lista str{};
    carattere ins;
    char scelta;
    bool run;
    bool bad;
    do {
        cout << "Scrivere i caratteri da convertire in binario:" << endl;
        cin >> ins.binario;
        inserimentoInCoda(str, ins);
        cout << "Conversione: ";

        do {
            cout << "Vuoi continuare? s/n:" << endl;
            cin >> scelta;

            switch (scelta) {
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
                    cout << "Carattere non ammesso" << endl;

            }
        } while (bad);
    } while (run);


    stampaLista(str);


// 4 Punti
}
