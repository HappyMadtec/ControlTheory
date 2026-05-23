#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <QVector>


class TransferFunction
{
public:
    TransferFunction();
    void calculatePoles();
    void calculateZeros();

protected:
    QVector<double> m_numerator;
    QVector<double> m_denumerator;
    QVector<double> m_poles;
    QVector<double> m_zeros;

    QVector<QVector<double>> m_closedLoopTransferFunction;
    QVector<QVector<double>> m_openedLoopTransferFunction;

};

#endif // TRANSFERFUNCTION_H
