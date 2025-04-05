#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <QList>
#include <QString>
#include <QDebug>
#include <complex>
#include <cmath>

/**
 * @brief The TransferFunction class
 * @arg   Two vectors one for zeros and one for poles
 * @arg   Or a string that will be splitted by "/" to distingush zeros from poles
 * @date  03.04.2025
 */

class TransferFunction {

public:

    // Constructors
    TransferFunction(QList<double> arrZero, QList<double> arrPole);
    TransferFunction(QString string_FT);

    // Destructors
    ~TransferFunction();

    // Form
    const QString             & ftArrayToString ();
    const QList<double> & ftStringToVector();

    // Calculation
    QList<std::complex<double> > polynomeSolution(const QList<double> &polynom);

    //getters
    const QList<std::complex<double>> &sol_poles () {return m_sol_poles;}
    const QList<std::complex<double>> &sol_zeros () {return m_sol_zeros;}

protected:
    QList<double>               m_arr_Zero;
    QList<double>               m_arr_Pole;
    QList<std::complex<double>> m_sol_poles;
    QList<std::complex<double>> m_sol_zeros;
    QString                     m_string_FT;
};

#endif // TRANSFERFUNCTION_H

