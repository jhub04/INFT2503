#include <iostream>

int main() {
  constexpr int length { 5 };
  constexpr double lowerLimit { 10.0 };
  constexpr double upperLimit { 20.0 };

  int lowerCount { 0 };
  int middleCount { 0 };
  int upperCount { 0 };

  std::cout << "Du skal skrive inn " << length << " temperaturer.\n";


  for (int i = 0; i < length; i++) {
    double temperature;
    std::cout << "Temperatur nr " << i + 1 << ": ";
    std::cin >> temperature;

    if (temperature < lowerLimit) {
      lowerCount++;
    }
    else if (temperature <= upperLimit) {
      middleCount++;
    }
    else {
      upperCount++;
    }
  }
  std::cout << '\n';
  std::cout << "Antall under " << lowerLimit << " er " << lowerCount << "\n";
  std::cout << "Antall mellom " << lowerLimit << " og " << upperLimit << " er " << middleCount << "\n";
  std::cout << "Antall over " << upperLimit << " er " << upperCount << "\n";

  return 0;
}