#include <fstream>
#include <iostream>

void read_temperatures(double temperatures[], int length);

int main() {
  constexpr int length{5};
  double temperatures[length];

  constexpr double lowerLimit{10.0};
  constexpr double upperLimit{20.0};

  int lowerCount{0};
  int middleCount{0};
  int upperCount{0};

  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++) {
    if (temperatures[i] < lowerLimit) {
      lowerCount++;
    } else if (temperatures[i] <= upperLimit) {
      middleCount++;
    } else {
      upperCount++;
    }
  }

  std::cout << "Antall under " << lowerLimit << " er " << lowerCount << "\n";
  std::cout << "Antall mellom " << lowerLimit << " og " << upperLimit << " er " << middleCount << "\n";
  std::cout << "Antall over " << upperLimit << " er " << upperCount << "\n";

  return 0;
}

void read_temperatures(double temperatures[], int length) {
  constexpr char filename[] = "../temps.txt"; // CWD er cmake-build-debug av en eller annen grunn i CLion
  std::ifstream file;
  file.open(filename);

  if (!file) {
    std::cerr << "Feil ved åpning av fil." << std::endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++) {
    file >> temperatures[i];
  }
}
