#include "../TransferFunction.h"

TransferFunction::TransferFunction(QList<double> arrZero, QList<double> arrPole): m_arr_Pole(std::move(arrPole)), m_arr_Zero(std::move(arrZero))
{
    if(! m_arr_Zero.isEmpty())
        this->m_sol_zeros = polynomeSolution(m_arr_Zero);

    if(! m_arr_Pole.isEmpty())
        this->m_sol_poles = polynomeSolution(m_arr_Pole);

}

TransferFunction::TransferFunction(QString string_FT) : m_string_FT(string_FT)
{
}

TransferFunction::~TransferFunction() = default;

QList<std::complex<double>> TransferFunction::polynomeSolution(const QList<double> &polynom)
{
    /**
     * Example: ax^3 + bx^2 + cx + d = 0
     * polynom = [a, b, c, d]
     */
    QList<std::complex<double>> toReturn;

    if (polynom.size() != 4) {
        qWarning() << "Invalid polynomial size. Expected degree 3 (4 coefficients)";
        return toReturn;
    }

    double a = polynom[0];
    double b = polynom[1];
    double c = polynom[2];
    double d = polynom[3];

    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);

    qInfo() << "Calculating delta";

    double delta = std::pow(q / 2.0, 2) + std::pow(p / 3.0, 3);

    std::complex<double> u = std::pow(std::complex<double>(-q / 2.0 + std::sqrt(delta), 0), 1.0 / 3.0);
    std::complex<double> v = std::pow(std::complex<double>(-q / 2.0 - std::sqrt(delta), 0), 1.0 / 3.0);

    std::complex<double> y1 = u + v;
    std::complex<double> x1 = y1 - (b / (3.0 * a));

    std::complex<double> omega1(-0.5,  std::sqrt(3) / 2.0);
    std::complex<double> omega2(-0.5, -std::sqrt(3) / 2.0);

    std::complex<double> x2 = omega1 * u + omega2 * v - (b / (3.0 * a));
    std::complex<double> x3 = omega2 * u + omega1 * v - (b / (3.0 * a));

    toReturn.push_back(x1);
    toReturn.push_back(x2);
    toReturn.push_back(x3);

    return toReturn;
}
