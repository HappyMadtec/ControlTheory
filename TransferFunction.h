#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <vector>
#include <QString>

/**
 * @brief The TransferFunction class
 * @arg   Two vectors one for zeros and one for poles
 * @arg   Or a string that will be splitted by "/" to distingush zeros from poles
 * @date  03.04.2025
 */

class TransferFunction {

public:

    // Constructors
    TransferFunction(std::vector<double> arrZero, std::vector<double> arrPole);
    TransferFunction(QString string_FT);

    // Destructors
    virtual ~TransferFunction();

    // Form
    const QString             & ftArrayToString ();
    const std::vector<double> & ftStringToVector();

    // Calculation
    const std::vector<double> & polynomeSolution (const std::vector<double> &polynom);

protected:
    std::vector<double> m_arr_Zero;
    std::vector<double> m_arr_Pole;
    std::vector<double> m_sol_poles;
    std::vector<double> m_sol_zeros;
    QString             m_string_FT;
};

#endif // TRANSFERFUNCTION_H
