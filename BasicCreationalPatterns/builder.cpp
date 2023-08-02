#include <iostream>
#include <string>

// Product class that we want to build
class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void showPizza() const {
        std::cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce, and " << topping_ << " topping." << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

// Abstract builder interface
class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}
    virtual PizzaBuilder& buildDough() = 0;
    virtual PizzaBuilder& buildSauce() = 0;
    virtual PizzaBuilder& buildTopping() = 0;
    virtual Pizza build() = 0;
};

// Concrete builder for Margherita Pizza
class MargheritaPizzaBuilder : public PizzaBuilder {
public:
    MargheritaPizzaBuilder() {
        pizza_.setDough("thin crust");
        pizza_.setSauce("tomato");
        pizza_.setTopping("mozzarella cheese");
    }

    PizzaBuilder& buildDough() override {
        pizza_.setDough("thin crust");
        return *this;
    }

    PizzaBuilder& buildSauce() override {
        pizza_.setSauce("tomato");
        return *this;
    }

    PizzaBuilder& buildTopping() override {
        pizza_.setTopping("mozzarella cheese");
        return *this;
    }

    Pizza build() override {
        return pizza_;
    }

private:
    Pizza pizza_;
};

int main() {
    // Create the Builder
    MargheritaPizzaBuilder builder;

    // Construct the pizza using method chaining
    Pizza pizza = builder.buildDough()
                         .buildSauce()
                         .buildTopping()
                         .build();

    // Display the pizza
    pizza.showPizza();

    return 0;
}
