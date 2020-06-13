#ifndef CALCULATOR_BINARYBLOCK_H
#define CALCULATOR_BINARYBLOCK_H

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
      answer_ = value1_ + value2_;
    }

    if (operation == Subtraction) {
      answer_ = value1_ - value2_;
    }

    if (operation == Multiplication) {
      answer_ = value1_ * value2_;
    }

    if (operation == Division) {
      answer_ = value1_ / value2_;
    }

    if (operation == Degree) {
      answer_ = pow(value1_, value2_);
    }
  }
  [[nodiscard]] double Answer() const { return answer_; }
};

#endif // CALCULATOR_BINARYBLOCK_H
