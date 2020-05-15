#ifndef CALCULATOR_BINARYBLOCK_H
#define CALCULATOR_BINARYBLOCK_H

#include "BinaryOperation.h"
#include "UnaryBlock.h"

class BinaryBlock {
private:
  double value1_ = 0;
  double value2_ = 0;
  double answer_ = 0;
  operations operation;

public:
  BinaryBlock(const double &v1, const double &v2, operations o)
      : value1_(v1), value2_(v2), operation(o) {

    if (operation == Sum) {
      class Sum block(value1_, value2_);
      answer_ = block.Answer();
    }

    if (operation == Subtraction) {
      class Subtraction block(value1_, value2_);
      answer_ = block.Answer();
    }

    if (operation == Multiplication) {
      class Multiplication block(value1_, value2_);
      answer_ = block.Answer();
    }

    if (operation == Division) {
      class Division block(value1_, value2_);
      answer_ = block.Answer();
    }

    if (operation == Degree) {
      class Degree block(value1_, value2_);
      answer_ = block.Answer();
    }
  }
  [[nodiscard]] double Answer() const { return answer_; }
};

#endif // CALCULATOR_BINARYBLOCK_H
