#ifndef CALCULATOR_BINARYOPERATION_H
#define CALCULATOR_BINARYOPERATION_H

#include <cmath>
#include <iostream>

class BinaryOperation {
protected:
  double number1_ = 0;
  double number2_ = 0;
  double answer_ = 0;

public:
  BinaryOperation(const double &n1, const double &n2)
      : number1_(n1), number2_(n2) {}
  [[nodiscard]] double Answer() const { return answer_; }
};

class Sum : public BinaryOperation {
public:
  Sum(const double &n1, const double &n2) : BinaryOperation(n1, n2) {
    answer_ = number1_ + number2_;
  }
};

class Subtraction : public BinaryOperation {
public:
  Subtraction(const double &n1, const double &n2) : BinaryOperation(n1, n2) {
    answer_ = number1_ - number2_;
  }
};

class Multiplication : public BinaryOperation {
public:
  Multiplication(const double &n1, const double &n2) : BinaryOperation(n1, n2) {
    answer_ = number1_ * number2_;
  }
};

class Division : public BinaryOperation {
public:
  Division(const double &n1, const double &n2) : BinaryOperation(n1, n2) {
    answer_ = number1_ / number2_;
  }
};

class Degree : public BinaryOperation { // n2>0
public:
  Degree(const double &n1, const double &n2) : BinaryOperation(n1, n2) {
    answer_ = pow(n1, n2);
  }
};

#endif // CALCULATOR_BINARYOPERATION_H
