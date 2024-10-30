1. Compile/ run linear interpolation.c
2. Compile/ run newton.c
3. In order for the methods to reach an error of <= 1.0e-6, bisection required 20 iterations, linear interpolation 15 iterations, and the Newton Method only 8 iterations. 
4. Bisection and linear interpolation may not always find a root with arbitrary inputs due to the parabola-like form of the function. There are two roots for the function, but selecting two starting values far from the center will cause f(a) * f(b) to be > 0, invalidating the search. The Newton algorithm however, is more robust and can find either root. 

Specifying a precision under the machine precision for the double data type (e ~ 10-16) resulted in the calculated error for each method to be 0. This is unlikely to be true though, and it is likely a result of a and b not being alterable by the addition of very small values, thus resulting in their difference being exactly 0. 
