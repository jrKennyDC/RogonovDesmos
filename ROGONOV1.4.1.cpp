
#include <iostream>
#include <cmath>
#include <vector>

struct EquationSolution {
    std::string equationType;
    std::string solution;

    EquationSolution(const std::string& type, const std::string& sol) : equationType(type), solution(sol) {}
};

class EquationSolver {
private:
    double a, b, c;
    std::vector<EquationSolution> history;

public:
    EquationSolver(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    void addToHistory(const std::string& type, const std::string& sol) {
        history.emplace_back(type, sol);
    }

    void printHistory() {
        std::cout << "\nИстория решений уравнений:\n";
        for (const auto& entry : history) {
            std::cout << "[" << entry.equationType << "] " << entry.solution << "\n";
        }
    }

    void solveLinear() {
        if (a == 0) {
            if (b == 0) {
                addToHistory("Линейное", "Уравнение недопустимо!");
            } else {
                double solution = -c / b;
                addToHistory("Линейное", "x = " + std::to_string(solution));
            }
        } else {
            addToHistory("Линейное", "Уравнение не является линейным.");
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
            addToHistory("Квадратное", "x = " + std::to_string(root));
        } else if (discriminant > 0) {
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            addToHistory("Квадратное", "x1 = " + std::to_string(root1) + " и x2 = " + std::to_string(root2));
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
            addToHistory("Квадратное", "x1 = " + std::to_string(realPart) + " + " + std::to_string(imaginaryPart) + "i и x2 = " + std::to_string(realPart) + " - " + std::to_string(imaginaryPart) + "i");
        }
    }
};

int main() {
    system("chcp 65001");
    char equationType;
    double a, b, c;

    EquationSolver solver(0, 0, 0); // Создаем экземпляр для доступа к истории

    do {
        std::cout << "Выберите тип уравнения (l - линейное, q - квадратное, e - выход): ";
        std::cin >> equationType;

        switch (equationType) {
            case 'l':
                std::cout << "Введите коэффициенты линейного уравнения (ax + b = 0): ";
                std::cin >> a >> b;
                solver = EquationSolver(a, b, 0);
                solver.solveLinear();
                break;
            case 'q':
                std::cout << "Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0): ";
                std::cin >> a >> b >> c;
                solver = EquationSolver(a, b, c);
                solver.solveQuadratic();
                break;
            case 'e':
                std::cout << "Программа завершена.\n";
                break;
            default:
                std::cout << "Неправильный выбор уравнения.\n";
        }

        if (equationType != 'e') {
            solver.printHistory();
        }

    } while (equationType != 'e');

    return 0;
}
