#include "Enum_operations.h"
#include "Read_expression.h"
#include "Result_function.h"
#include <iostream>
#include <queue>
#include <variant>

int main() {
  try {
    std::queue<std::variant<double, operations>> values = read_expression();
    std::cout << "Answer: " << result(values);
  } catch (std::out_of_range &d) {
    std::cout << "Wrong data. Try typing again. " << d.what() << std::endl;
  } catch (std::invalid_argument &d) {
    std::cout << "Incorrect x value. Try typing again." << std::endl;
  }
  return 0;
}
