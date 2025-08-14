#include <iostream>

int find_sum(const int *table, int length) {
  // const int *table = &table[0]
  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += table[i];
  }

  return sum;
}

int main() {
  constexpr int length = 20;
  int table[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int sum = 0;
  // Summen av de 10 første tallene
  sum = find_sum(table, 10);
  std::cout << "Summen av de 10 første tallene: " << sum << '\n';

  // Summen av de 5 neste tallene
  sum = find_sum(&table[10], 5);
  std::cout << "Summen av de 5 neste tallene: " << sum << '\n';

  // Summen av de 5 siste tallene
  sum = find_sum(&table[15], 5);
  std::cout << "Summen av de 5 siste tallene: " << sum << '\n';
  return 0;
}