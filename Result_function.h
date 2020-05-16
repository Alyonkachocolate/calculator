#ifndef CALCULATOR_RESULT_FUNCTION_H
#define CALCULATOR_RESULT_FUNCTION_H

bool is_unary_operation(const operations &o) {
  return o == UnaryMinus || o == Sin || o == Cos || o == tg || o == ctg ||
         o == Exp || o == Sqrt;
}
double result(std::queue<std::variant<double, operations>> &values) {
  std::stack<double> result;
  bool ok1 = false, ok2 = false; /// для проверки случаев выражения без чисел
  // или без операций
  size_t value = values.size();
  while (!values.empty()) {
    if (values.front().index() == 0) { /// если это число
      ok1 = true;
      result.push(std::get<double>(values.front())); /// кидаем это число на
      // стек
    } else {
      if (!ok1)
        throw std::out_of_range("No numbers.");
      ok2 = true;
      if (!is_unary_operation(std::get<operations>(values.front()))) { // если
        // это
        // бинарная операция
        if (result.size()<2)
          throw std::out_of_range("");
        double value2 = result.top();
        result.pop();
        double value1 = result.top();
        result.pop();
        BinaryBlock block(value1, value2, std::get<operations>(values.front()));
        result.push(block.Answer());
      } else { // если это унарная операция
        if (result.empty())
          throw std::out_of_range("");
        double value1 = result.top();
        result.pop();
        UnaryBlock block(value1, std::get<operations>(values.front()));
        result.push(block.Answer());
      }
    }
    values.pop();
  }
  // когда изначально было больше одного числа без операций - ошибка.
  if (!ok2 && value > 1)
    throw std::out_of_range("No operations.");
  /// единственное оставшееся число на стеке результата - ответ
  return (result.top());
}

#endif // CALCULATOR_RESULT_FUNCTION_H
