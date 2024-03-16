
#include <iostream>
#include <cmath>

class EquationSolver {
private:
    double a, b, c;

public:
    EquationSolver(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    void solveLinear() {
        if (a == 0) {
            if (b == 0) {
                std::cout << "The equation is invalid!\n";
            } else {
                double solution = -c / b;
                std::cout << "The solution is x = " << solution << "\n";
            }
        } else {
            std::cout << "The equation is not linear.\n";
        }
    }

    void solveQuadratic() {
        if (a == 0) {
            solveLinear();
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "The solutions are x1 = " << root1 << " and x2 = " << root2 << "\n";
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "The solution is x = " << root << "\n";
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            std::cout << "The solutions are x1 = " << realPart << " + " << imaginaryPart << "i and x2 = " << realPart << " - " << imaginaryPart << "i\n";
        }
    }
};

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients of the quadratic equation (ax^2 + bx + c = 0): ";
    std::cin >> a >> b >> c;

    EquationSolver eqSolver(a, b, c);

    std::cout << "\nSolving the quadratic equation:\n";
    eqSolver.solveQuadratic();

    std::cout << "\nEnter the coefficients of the linear equation (ax + b = 0): ";
    std::cin >> a >> b;
    eqSolver = EquationSolver(a, b, 0);

    std::cout << "\nSolving the linear equation:\n";
    eqSolver.solveLinear();

    return 0;
}
