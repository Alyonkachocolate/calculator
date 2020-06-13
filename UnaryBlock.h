#ifndef CALCULATOR_UNARYBLOCK_H
#define CALCULATOR_UNARYBLOCK_H

#include "Enum_operations.h"
#include "UnaryOperation.h"

class UnaryBlock {
private:
  double number_ = 0;
  double answer_ = 0;
  operations operation;

public:
  UnaryBlock(const double &v, operations o) : number_(v), operation(o) {

    if (operation == UnaryMinus) {
      answer_ = -number_;
    }

    if (operation == Sin) {
      answer_ = sin(number_);
    }
    if (operation == Cos) {
      answer_ = cos(number_);
    }

    if (operation == tg) {
      answer_ = tan(number_);
    }

    if (operation == ctg) {
      answer_ = 1 / tan(number_);
    }

    if (operation == Exp) {
      answer_ = exp(number_);
    }

    if (operation == Sqrt) {
      answer_ = sqrt(number_);
    }
  }

  [[nodiscard]] double Answer() const { return answer_; }
};

#endif // CALCULATOR_UNARYBLOCK_H
