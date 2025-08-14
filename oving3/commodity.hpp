#pragma once
#include <string>

class Commodity {
  public:
    Commodity(const std::string &name_, int id_, double price_);

    const std::string &get_name() const { return name; };
    int get_id() const { return id; }

    double get_price() const { return price; }
    double get_price(double quantity);

    void set_price(double newPrice) { price = newPrice; };

    double get_price_with_sales_tax();
    double get_price_with_sales_tax(double quantity);

  private:
    std::string name;
    int id;
    double price;
};
