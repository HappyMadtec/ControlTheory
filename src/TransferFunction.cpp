#include "../TransferFunction.h"

TransferFunction::TransferFunction(std::vector<double> arrZero, std::vector<double> arrPole): m_arr_Pole(arrPole), m_arr_Zero(arrZero)
{
}

TransferFunction::TransferFunction(QString string_FT) : m_string_FT(string_FT)
{
}

TransferFunction::~TransferFunction()
{

}

const std::vector<double> &TransferFunction::polynomeSolution(const std::vector<double> &polynom)
{
    /** Polynom example
     *
     *  ax^3 + bx^2 + cx + d = 0;
     *  vector = [a, b, c, d]
     *
     * */

    double a = polynom[0];
    double b = polynom[1];
    double c = polynom[2];
    double d = polynom[3];

    if(polynom.size() == 3)
    {
        double p = (3*a*c - b*b)/(3*a*a);
        double q = (2*b*b*b - 9*a*b*c + 27*a*a*d)/(27*a*a*a);

        /**
         * Notre polynome sera y^3 + py + q = 0
         * */

        double delta = (q*q/4) + (p*p*p/27);

        if(delta > 0){}
        if(delta < 0){}
        if(delta == 0){}
    }

}
