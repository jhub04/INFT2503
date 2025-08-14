#include <iostream>

int main() {
  // Oppgave 1 - a)
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  std::cout << "Adresse til i: " << &i << ", verdi: " << i << '\n';
  std::cout << "Adresse til j: " << &j << ", verdi: " << j << '\n';
  std::cout << "Adresse til p: " << &p << ", verdi: " << p << '\n';
  std::cout << "Adresse til q: " << &q << ", verdi: " << q << '\n';

  std::cout << std::endl;

  // Oppgave 1 - b)
  *p = 7; // i = *p = 7
  *q += 4; // j = *q = 5 + 4 = 9
  *q = *p + 1; // j = *q = 7 + 1 = 8
  p = q; // p peker nå på addressen til q. *p = *q = 8
  std::cout << *p << " " << *q << std::endl; // Vil da printe ut: 8 8

  return 0;
}

/* Oppgave 2
char *line = nullptr;
strcpy(line, "Dette er en tekst");

line er en nullpointer som betyr at den ikke peker på noen ting.
Siden line er nullpointer peker den til adresse 0 i RAM som er et ugyldig område å peke til
Når strcpy kalles vil det prøver metoden å lagre strengen på adresseområdet line peker til,
som er et ugyldig område. Derfor vil programmet kræsje

Når jeg kjørte programmet for meg selv endte jeg opp med denne feilmeldingen:
Process finished with exit code 139 (interrupted by signal 11:SIGSEGV)
Som betyr segmentation fault
*/

/* Oppgave 3
char text[5];
char *pointer = text; // pointer peker til addressen til text[0]
char search_for = 'e';
cin >> text;
while (*pointer != search_for) { samme som text[0] != search_for
  *pointer = search_for; // text[0] = e
  pointer++; // pointer peker nå til addressen til text[1]
}

Ting som kan gå galt:
1) Buffer overflow ved cin >> text dersom brukeren skriver inn et ord med flere enn 4 tegn
2) Hvis search_for ikke finnes i text vil pointer fortsette forbi strengens nullterminator og skrive 'e' videre i minnet
3) Programmet vil skrive over alle charsa i minnet med 'e' før search_for blir funnet, hvis det i det hele tatt eksisterer i text

*/
