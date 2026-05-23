#include "polynomialresolution.h"

polynomialResolution::polynomialResolution(const QVector<double> &coefs): m_coefs(coefs) {}


// convention ax^n + bx^n-1 ..... z => QVector <double> [ highest coef ----> lowest ]
void polynomialResolution::solve()
{
         if (m_coefs.size() == 2) solveLinear      (); //degree 1
    else if (m_coefs.size() == 3) solveQuadratic   (); //degree 2
    else if (m_coefs.size() == 4) solveCubic       (); //degree 3
    else if (m_coefs.size() == 5) solveQuartic     (); //degree 4
    else if (m_coefs.size() == 6) solveDurandKerner(); //degree 5
}

QVector<Complex> polynomialResolution::solveLinear()
{
    QVector<Complex> toReturn;
    Complex valueToReturn;

    Complex delta;
    double a = m_coefs.first();
    double b = m_coefs.last ();

    delta = -b/a;

    toReturn.append(delta);

    return toReturn;
}

QVector<Complex> polynomialResolution::solveQuadratic()
{
    QVector<Complex> toReturn;
    toReturn = deltaQuadratic(m_coefs[2], m_coefs[1], m_coefs[0]);
    return toReturn;
}

QVector<Complex> polynomialResolution::deltaQuadratic(double a, double b, double c)
{
    QVector<Complex> toReturn;

    double delta =  std::pow(b, 2) - 4*a*c;
    Complex x1 = .0;
    Complex x2 = .0;

    if (delta == 0)
    {
        x1 = -b/(2*a);
        x2 = -b/(2*a);

        toReturn.append(x1);
        toReturn.append(x2);
    }

    if (delta > 0)
    {
        x1 = std::pow(b, 2) + std::sqrt(delta);
        x2 = std::pow(b, 2) - std::sqrt(delta);

        toReturn.append(x1);
        toReturn.append(x2);
    }

    x1 = std::pow(b, 2) + std::sqrt(std::abs(delta) / (2*a));
    x2 = std::pow(b, 2) - std::sqrt(std::abs(delta) / (2*a));

    toReturn.append(x1);
    toReturn.append(x2);

    return toReturn;
}


