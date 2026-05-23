#ifndef POLYNOMIALRESOLUTION_H
#define POLYNOMIALRESOLUTION_H

#include <qcontainerfwd.h>
#include <QVector>
#include <complex>

using Complex = std::complex<double>;

class polynomialResolution
{
public:
    polynomialResolution(const QVector<double> &coefs);

    void solve();

    // QVector<Complex> solveOneDegreePolynomial();

protected:
    QVector<double> m_coefs;

    QVector<Complex> solveLinear();
    QVector<Complex> solveQuadratic();
    QVector<Complex> solveCubic();
    QVector<Complex> solveQuartic();
    QVector<Complex> solveDurandKerner();

    QVector<Complex> deltaQuadratic(double a = .0, double b = .0, double c = .0);
};

#endif // POLYNOMIALRESOLUTION_H
