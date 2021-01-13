#include <gtest/gtest.h>
#include <polynomial.h>

class PolynomialFixture : public ::testing::Test {
protected:
    // f(x) = 4*x³ + 1*x² + 5*x + 7
    static const int order{3U};
    const std::array<float, order + 1> coeffs{7.0f, 5.0f, 1.0f, 4.0f};
    Polynomial<order> m_polynomial{coeffs};
};

TEST_F(PolynomialFixture, construct_polynomial_third_order) {
    EXPECT_NO_FATAL_FAILURE(Polynomial<order> m_polynomial(coeffs));
}

TEST_F(PolynomialFixture, evaluate_at) {
    EXPECT_FLOAT_EQ(-253.0f, m_polynomial.EvaluateAt(-4.0f));
}

TEST_F(PolynomialFixture, first_derivative_at) {
    EXPECT_FLOAT_EQ(205.0f, m_polynomial.DerivativeAt(4.0f, 1U));
}

TEST_F(PolynomialFixture, second_derivative_at) {
    EXPECT_FLOAT_EQ(-118.0f, m_polynomial.DerivativeAt(-5.0f, 2U));
}

TEST_F(PolynomialFixture, third_derivative_at) {
    EXPECT_FLOAT_EQ(24.0f, m_polynomial.DerivativeAt(10.0f, 3U));
}

TEST_F(PolynomialFixture, fourth_derivative_at) {
    EXPECT_FLOAT_EQ(0.0f, m_polynomial.DerivativeAt(10.0f, 4U));
}

TEST_F(PolynomialFixture, curvature_at_2) {
    EXPECT_FLOAT_EQ(0.000269864f, m_polynomial.CurvatureAt(2.0f));
}

TEST_F(PolynomialFixture, curvature_at_minus_2) {
    EXPECT_FLOAT_EQ(0.0003907494f, m_polynomial.CurvatureAt(-2.0f));
}

// ---------- main ---------------------------------------------------------------------
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}