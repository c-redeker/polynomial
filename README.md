# Polynomial

# Description
Polynomial is a header-only library for working with polynomials like 
*f(x) = c3 * x³ + c2 * x² + c1 * x + c0*.  
The library is capable of:
- evaluating the value of the polynomial *f(x)* at any x
- calculating the n-th derivative *f <sup>(n)</sup>(x)* at any x
- calculating the curvature of the polynomial at any x  

Possible usages:
- Generation of artificial paths/trajectories for testing purposes 

# Dependencies
- GoogleTest (only if -DBUILD_TESTS=ON)

# Build
from repo root directory
```console
mkdir _build
cd _build
cmake .. -DBUILD_TESTS=<ON/OFF> -DCMAKE_INSTALL_PREFIX=<path-to-install-dir>
make
make install
```