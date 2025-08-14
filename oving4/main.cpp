#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<double> nums = {1, 2, 3, 4, 5};
  std::cout << "Front: "<< nums.front() << '\n';
  std::cout << "Back: " << nums.back() << '\n';

  nums.emplace(nums.begin() + 1, 6);
  std::cout << "Front etter emplace: "<< nums.front() << '\n';

  auto it = std::find(nums.begin(), nums.end(), 4);

  if (it != nums.end()) {
    std::cout << "Verdien funnet er: " <<*it << '\n';
  } else {
    std::cout << "Tallet finnes ikke i nums" << '\n';
  }

  return 0;
}