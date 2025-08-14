#include <iostream>

int main() {
  /*
  int a = 5;    // Greit
  int &b;       // Feil: Referanse kan ikke være uinitialisert
  int *c;       // Greit men skummelt med uinitialisert pointer
  c = &b;       // Greit
  *a = *b + *c; // Feil: a er ikke en peker og kan derfor ikke dereferes. b er en referanse, ikke er peker, og kan derfor heller ikke dereferes
  &b = 2;       // Feil: man kan ikke tilornde til en adresse
  */

  // Endret kode slik at den kompilerer
  int a = 5;
  int &b = a;
  int *c;
  c = &b;
  a = b + *c;
  b = 2;
}
