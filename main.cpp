#include <iostream>
using namespace std;
#define BYTE 8
struct carattere
{
    char binario[BYTE + 1];
    carattere* succ;
};
typedef carattere* lista;
// Inserisce il carattere “daIns” in coda alla lista “stringa”.
void inserimentoInCoda(lista& stringa, carattere daIns)
{
// 3 Punti
}
// Rimuove tutti gli elementi della lista “stringa”.
void svuotaLista(lista& stringa)
{
// 3 Punti
}
/* Stampa a schermo gli elementi della lista “stringa” come nell'esempio di
esecuzione. */
void stampaLista(lista stringa)
{
// 2 Punti
}
// Restituisce il valore di “n” elevato alla potenza “esponente”.
int potenza(int n, unsigned esponente)
{
// 2 Punti
}
/* Esegue la conversione in codice ASCII (binario) del carattere “input”,
rappresentandola come una sequenza di caratteri “0” e “1” da inserire nella
stringa “convertito”. */
void conversioneBinaria(char* convertito, char input)
{
// 4 Punti
}
/* Programma principale: chiama le funzioni precedenti e gestisce la
continuazione o la terminazione del programma. */
int main()
{
// 4 Punti
}
