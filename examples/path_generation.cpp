#include <iostream>
#include <polynomial.h>
#include <vector>

struct Vertex {
    float x{};
    float y{};
    float curvature{};
};

using Path = std::vector<Vertex>;

int main() {
    // f(x) = 4*x³ + 1*x² + 5*x + 7
    static const int order{3U};
    const std::array<float, order + 1> coeffs{7.0f, 5.0f, 1.0f, 4.0f};
    Polynomial<order> polynomial{coeffs};

    Path path{};

    const int count_points{100U};
    for (int i = 0; i < count_points; i++) {
        Vertex vertex{};
        vertex.x = static_cast<float>(i);
        vertex.y = polynomial.EvaluateAt(vertex.x);
        vertex.curvature = polynomial.CurvatureAt(vertex.x);
        path.push_back(vertex);
    }

    std::cout << "Path successfully generated! Terminate program." << std::endl;
    return 0;
}