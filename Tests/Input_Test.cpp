#include "gtest/gtest.h"
#include "../TransferFunction.h"


TEST(Test_Input_Output_Function, creation)
{
    // initialize the creation of a transfer Function
    QString polynome;
    QList<double> poles{};
    QList<double> zeros{};

    // for the polynomial x^3 - 6x^2 + 11x -6  ==== > delta < 0
    QList<double> inputPol1 = {-1, -6, 11, -6};
    QList<double> inputPol2;
    TransferFunction tf (inputPol1, inputPol2);

    ASSERT_TRUE(tf.sol_zeros().size() == 3);

    QList<std::complex<double>> expected = {
        std::complex<double>(0.78000275304767364, 4.8151060134599231),
        std::complex<double>(-3.0172622711921826, -2.622754029530693),
        std::complex<double>(-3.7627404818554906, -2.1923519839292305)
    };

       for (int i = 0; i < expected.size(); ++i) {
        ASSERT_EQ(tf.sol_zeros()[i].real(), expected[i].real());
           ASSERT_EQ(tf.sol_zeros()[i].imag(), expected[i].imag());  // imaginary part should be 0
    }

    // take the input

    // test the regular expression

    // test the good detection of the format for the ouptut of the function

    //

}
