#ifndef CALCULATOR_READ_EXPRESSION_H
#define CALCULATOR_READ_EXPRESSION_H
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <variant>

std::queue<std::variant<double, operations>> read_expression() {
  std::map<std::string, operations> operand = {
      {"+", Sum},      {"-", Subtraction}, {"*", Multiplication}, {"^", Degree},
      {"/", Division}, {"sin", Sin},       {"cos", Cos},          {"tg", tg},
      {"ctg", ctg},    {"exp", Exp},       {"sqrt", Sqrt},
  };
  std::queue<std::variant<double, operations>> values; // стек для основной
  // работы - содержит в себе шаьлон для реализации двух типов - вещественных
  // чисел и операций
  std::stack<operations> Stack; //стек для операторов

  /// считываем всю строку выражения и бросаем её в поток строк

  std::cout << "Please use keywords "
               "such as: sin, cos, tg, ctg, exp, sqrt, and ^ for "
               "degree. Also you can use const pi = 3.1415926 and e = 2"
               ".7182818."
            << std::endl;
  std::cout << "For example: 2*sin(4-sqrt(38.9)/5)" << std::endl;
  std::cout << "Expression for calculations: " << std::endl;
  std::string command;
  getline(std::cin, command);
  std::istringstream date_stream(command);

  /// считываем посимвольно выражение.
  /// все элементы можно разделить на три группы:
  /// 1 - числа, 2 - операции, 3 - скобки
  int c = date_stream.get();
  bool unary_minus = true; // для проверки на то, что символ перед
  // минусом - не цифра, тогда это точно унарный минус

  double x = 0; /// переменная, которая может запрашиваться у пользователя
  bool for_x = false; /// проверяет, знаем ли мы значение x
  while (c != EOF) {
    /// считывание цифр и бросание их на основной стек
    if (isnumber(c) || c == '.') {
      std::string s;
      do {
        unary_minus = false;
        s += (char)c;
      } while ((isnumber(c = date_stream.get()) || c == '.') && c != EOF);
      double a = std::stod(s);
      values.push(a);
      if (c == ' ')
        c = date_stream.get();
    } else {

      /// работа по считыванию операций и бросание их на особый стек операций
      /// и, если нужно, перебрасывание на основной стек
      if (c != '(' && c != ')') {
        std::string s1;
        bool ok = true; //проверка, что уже прочитанное не является
        // каким-либо оператором, для случае по пример -sin(x)
        do {
          (s1 += (char)c);
          if (operand.count(s1) > 0 || s1 == "pi" || s1 == "e" || s1 == "x")
            ok = false;
        } while (!isnumber(c = date_stream.get()) && c != ')' && c != '(' &&
                 c != EOF && ok);
        if (s1 != "pi" && s1 != "e" && s1 != "x" && operand.count(s1) == 0)
          throw std::out_of_range("It is: " + s1);
        if (s1 == "x") {
          if (for_x)
            values.push(x);
          else {
            for_x = true;
            std::cout << "Please enter the value of the variable x: "
                      << std::endl;
            std::string com;
            getline(std::cin, com);
            x = std::stod(com);
            // вот здесь может выкинуться исключение std::invalid_argument
            values.push(x);
          }
        } else {
          if (s1 == "pi")
            values.push(M_PI);
          else {
            if (s1 == "e")
              values.push(M_E);
            else {
              operations o = operand.at(s1); // текущая операция
              if (s1 == "-" && unary_minus)
                o = UnaryMinus;
              if (!Stack.empty()) {
                while ((!Stack.empty() && Stack.top() <= o) &&
                       Stack.top() != bkt_left) {
                  values.push(Stack.top());
                  Stack.pop();
                }
              }
              Stack.push(o);
            }
          }
        }
        if (c == ' ')
          c = date_stream.get();
      } else {

        /// работа с скобочками. в случае '(' (bkt_left) - кидаем на стек
        /// операций, если же это ')' (bkt_right) - кидаем на основной стек
        /// все операции в вырвжение, которое закрывет эта скобка
        if (c == '(')
          Stack.push(bkt_left);
        else {
          while (Stack.top() != bkt_left) {
            values.push(Stack.top());
            Stack.pop();
          }
          Stack.pop();
        }
        unary_minus = true;
        c = date_stream.get();
        if (c == ' ')
          c = date_stream.get();
      }
    }
  }

  /// все оставшиеся операции из стека операций кидаем на основной стек
  if (!Stack.empty()) {
    if (Stack.top() == bkt_left)
      Stack.pop(); // если осталась лишняя '(' скобочка
    if (!Stack.empty()) // копируем всё в основной стек
      while (!Stack.empty()) {
        values.push(Stack.top());
        Stack.pop();
      }
  }
  return values;
}

#endif // CALCULATOR_READ_EXPRESSION_H
