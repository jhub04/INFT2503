#include <iostream>

int main() {
  double number;

  // Definer en peker som skal peke til number
  double *ptrNumber = &number;

  // Definer en referanse som skal referere til number.
  double &refNumber = number;

  //Vis tre måter å få tilordnet verdi til number på
  // 1)
  number = 5.0;
  std::cout << "Med variabel: "<< number << '\n';
  // 2)
  *ptrNumber = 10.0;
  std::cout << "Med peker: " << number << '\n';

  // 3)
  refNumber = 15.0;
  std::cout << "Med referanse: " << number << '\n';
}
