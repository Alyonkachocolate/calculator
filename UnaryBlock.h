#ifndef CALCULATOR_UNARYBLOCK_H
#define CALCULATOR_UNARYBLOCK_H

#include "Enum_operations.h"
#include "UnaryOperation.h"

class UnaryBlock {
private:
  double value_ = 0;
  double answer_ = 0;
  operations operation;

public:
  UnaryBlock(const double &v, operations o) : value_(v), operation(o) {

    if (operation == UnaryMinus) {
      class UnaryMinus block(value_);
      answer_ = block.Answer();
    }

    if (operation == Sin) {
      class Sin block(value_);
      answer_ = block.Answer();
    }
    if (operation == Cos) {
      class Cos block(value_);
      answer_ = block.Answer();
    }

    if (operation == tg) {
      class tg block(value_);
      answer_ = block.Answer();
    }

    if (operation == ctg) {
      class ctg block(value_);
      answer_ = block.Answer();
    }

    if (operation == Exp) {
      class Exp block(value_);
      answer_ = block.Answer();
    }

    if (operation == Sqrt) {
      class Sqrt block(value_);
      answer_ = block.Answer();
    }
  }

  [[nodiscard]] double Answer() const { return answer_; }
};

#endif // CALCULATOR_UNARYBLOCK_H
