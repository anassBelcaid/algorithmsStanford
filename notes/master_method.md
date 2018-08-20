# The master method #

The master method is a mathematical tool to study the complexity of recursive
algorithms.


For more details, we refer the [wikipedia article](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))


## Generic form ##

The generic form of a recursive call is :

$$
T(n) = a T(\dfrac{n}{b}) + f(n)
$$

* **a** : is the number of subproblems
* **b** : b is the dividing factor for the size.
* **f(n)** : is the cost for the `conquer` phase.

or in more specefic format

$$
T(n) = a T\big(\dfrac{n}{b}\big) + \mathcal{O}(n^d) 
$$

* **d**: is the complexity of the merging step

## Result ##

$$
T(n) =\begin{cases}  
 \mathcal{O}\big(n^dlog(n)\big)\quad a=b^d\\
 \mathcal{O}\big(n^d\big) \quad a<b^d \\
 \mathcal{O}\big(n^{log_b(a)}\big) \quad a>b^d
\end{cases}
$$

