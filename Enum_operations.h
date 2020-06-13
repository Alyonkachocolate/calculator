#ifndef CALCULATOR_ENUM_OPERATIONS_H
#define CALCULATOR_ENUM_OPERATIONS_H

enum operations {
  // Unary
  Sin = 11,
  Cos = 21,
  tg = 31,
  ctg = 41,
  Exp = 51,
  Sqrt = 61,
  UnaryMinus = 13,

  // Binary
  Degree = 12,
  Multiplication = 14,
  Division = 24,
  Sum = 15,
  Subtraction = 25,

  bkt_right = 16, // )
  bkt_left = 26  // (
};

#endif // CALCULATOR_ENUM_OPERATIONS_H
