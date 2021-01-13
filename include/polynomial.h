#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H

#include <cmath>
#include <array>

template<int order>
class Polynomial {
public:
    /*!
     *
     * @param coefficients of n-th order polynomial (c_0, c_1, c_2, ... c_n+1)
     */
    explicit Polynomial(const std::array<float, order + 1U> &coefficients) {
        m_coefficients = coefficients;
    }

    float EvaluateAt(const float x) {
        float result{};
        for (unsigned int i = 0; i < m_coefficients.size(); i++) {
            result += m_coefficients[i] * std::pow(x, i);
        }
        return result;
    }

    float DerivativeAt(const float x, const unsigned int derivation_order) {
        float result{0.0f};
        if (order >= derivation_order) {
            for (unsigned int i = derivation_order; i < m_coefficients.size(); i++) {
                float new_coefficient{m_coefficients[i]};
                for (unsigned int j = 0; j < derivation_order; j++) {
                    new_coefficient *= static_cast<float>(i - j);
                }

                result += new_coefficient * std::pow(x, i - derivation_order);
            }
        }
        return result;
    }

    float CurvatureAt(const float x) {
        const auto first_derivative = DerivativeAt(x, 1U);
        const auto second_derivative = DerivativeAt(x, 2U);
        return std::abs(second_derivative) / std::pow((1 + std::pow(first_derivative, 2.0f)), 1.5f);
    }

private:
    std::array<float, order + 1U> m_coefficients;
};

#endif //POLYNOMIAL_POLYNOMIAL_H
