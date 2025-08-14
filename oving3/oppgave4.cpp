#include <iostream>

int main() {
  // a)
  std::cout << "Skriv inn tre ord separert med mellomrom: ";
  std::string word1, word2, word3;

  std::cin >> word1 >> word2 >> word3;

  // b)
  std::string sentence = word1 + " " + word2 + " " + word3 + ".";

  // c)
  std::cout << "Lengden til word1: " << word1.length() << '\n';
  std::cout << "Lengden til word2: " << word2.length() << '\n';
  std::cout << "Lengden til word3: " << word3.length() << '\n';
  std::cout << "Lengden til sentence: " << sentence.length() << '\n';

  // d)
  std::string sentence2 = sentence;

  // e)
  if (sentence2.length() >= 13) { // Må være minst 13 tegn for pos 12 å eksistere
    sentence2[10] = 'X';
    sentence2[11] = 'X';
    sentence2[12] = 'X';
  }

  std::cout << "Sentence: " << sentence << '\n';
  std::cout << "Sentence2: " << sentence2 << '\n';

  // f)
  std::string sentence_start = "";
  constexpr int interval_length = 5;
  if (sentence.length() >= interval_length + 1) { // Må være minst 6 tegn for pos 5 å eksistere
    for (int i = 0; i < interval_length; i++) {
      sentence_start += sentence[i];
    }
  } // Må være minst 6 tegn for pos 5 å eksistere


  std::cout << "Sentence: " << sentence << '\n';
  std::cout << "Sentence_start: " << sentence_start << '\n';

  // g)
  if (sentence.find("hallo") != std::string::npos) {
    std::cout << "'hallo' finnes i sentence" << '\n';
  } else {
    std::cout << "'hallo' finnes ikke i sentence" << '\n';
  }

  // h)
  size_t pos = sentence.find("er");
  if (pos == std::string::npos) {
    std::cout << "'er' finnes ikke i setningen" << '\n';
  } else {
    std::cout << "'er' forekommer på posisjon(er): ";
    while (pos != std::string::npos) {
      std::cout << pos << " ";
      pos = sentence.find("er", pos + 1);
    }
    std::cout << std::endl;
  }
}