#ifndef CALCULATOR_ENUM_OPERATIONS_H
#define CALCULATOR_ENUM_OPERATIONS_H

enum operations {
  // Unary
  Sin,
  Cos,
  tg,
  ctg,
  Exp,
  Sqrt,
  UnaryMinus,

  // Binary
  Degree,
  Multiplication,
  Division,
  Sum,
  Subtraction,

  bkt_right, // )
  bkt_left   // (
};

#endif // CALCULATOR_ENUM_OPERATIONS_H
