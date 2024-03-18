#include <iostream>
#include <cmath>
using namespace std;
class EquationSolver {
private:
    double a, b, c;

public:
    EquationSolver(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    void solveLinear() {
        if (a == 0) {
            if (b == 0) {
                std::cout << "Уравнение недопустимо!\n";
            } else {
                double solution = -c / b;
                std::cout << "Решение: x = " << solution << "\n";
            }
        } else {
            std::cout << "Уравнение не является линейным.\n";
        }
    }

    void solveQuadratic() {
        if (a == 0) {
            solveLinear();
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (std::abs(discriminant) < 1e-10) {
            double root = -b / (2 * a);
            std::cout << "Решение: x = " << root << "\n";
        } else if (discriminant > 0) {
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "Решения: x1 = " << root1 << " и x2 = " << root2 << "\n";
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
            std::cout << "Решения: x1 = " << realPart << " + " << imaginaryPart << "i и x2 = " << realPart << " - " << imaginaryPart << "i\n";
        }
    }
};

int main() 
{
    system("chpcp 65001");
    double a, b, c;
    std::cout << "Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0): ";
    std::cin >> a >> b >> c;

    EquationSolver eqSolver(a, b, c);

    std::cout << "\nРешение квадратного уравнения:\n";
    eqSolver.solveQuadratic();

    std::cout << "\nВведите коэффициенты линейного уравнения (ax + b = 0): ";
    std::cin >> a >> b;
    eqSolver = EquationSolver(a, b, 0);

    std::cout << "\nРешение линейного уравнения:\n";
    eqSolver.solveLinear();

    return 0;
}