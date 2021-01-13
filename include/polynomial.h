#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H

#include <cmath>
#include <array>
#include <cassert>

template<int order>
class Polynomial {
public:
    explicit Polynomial(std::array<float, order + 1U> &coefficients) {
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


private:
    std::array<float, order + 1U> m_coefficients;
};

#endif //POLYNOMIAL_POLYNOMIAL_H
