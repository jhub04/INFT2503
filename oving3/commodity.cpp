#include "commodity.hpp"

constexpr double sales_tax = 0.25;

Commodity::Commodity(const std::string &name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

double Commodity::get_price(double quantity) {
  return Commodity::get_price() * quantity;
}

double Commodity::get_price_with_sales_tax() {
  return Commodity::get_price() * (1 + sales_tax);
}

double Commodity::get_price_with_sales_tax(double quantity) {
  return Commodity::get_price_with_sales_tax() * quantity;
}








