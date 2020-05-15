#ifndef CALCULATOR_UNARYOPERATION_H
#define CALCULATOR_UNARYOPERATION_H

#include <cmath>
#include <iostream>

class UnaryOperation {
protected:
  double number_ = 0;
  double answer_ = 0;

public:
  explicit UnaryOperation(const double &n) : number_(n) {}
  [[nodiscard]] double Answer() const { return answer_; }
};

class UnaryMinus : public UnaryOperation {
public:
  explicit UnaryMinus(const double &n) : UnaryOperation(n) {
    answer_ = -number_;
  }
};

class Sin : public UnaryOperation {
public:
  explicit Sin(const double &n) : UnaryOperation(n) { answer_ = sin(number_); }
};

class Cos : public UnaryOperation {
public:
  explicit Cos(const double &n) : UnaryOperation(n) { answer_ = cos(number_); }
};

class tg : public UnaryOperation {
public:
  explicit tg(const double &n) : UnaryOperation(n) { answer_ = tan(number_); }
};

class ctg : public UnaryOperation {
public:
  explicit ctg(const double &n) : UnaryOperation(n) {
    answer_ = 1 / tan(number_);
  }
};

class Exp : public UnaryOperation {
public:
  explicit Exp(const double &n) : UnaryOperation(n) { answer_ = exp(number_); }
};

class Sqrt : public UnaryOperation {
public:
  explicit Sqrt(const double &n) : UnaryOperation(n) {
    answer_ = sqrt(number_);
  }
};

#endif // CALCULATOR_UNARYOPERATION_H
