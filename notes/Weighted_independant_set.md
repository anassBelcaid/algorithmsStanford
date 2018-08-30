# Weghted indpendant set #

The problem is givena graph $G(V,E)$, is the to compute the maximum weighted
set. i.e a set of disconnected nodes with maximum weight. The problem must
choose a set $S\subset V$ such as $\sum_{s\in S} ws$ is maximal.


## Opitmal Structure ##

Using the `Dynamic paradigm`, an optimal structure on **paths**  over the last vertex $\mathbf{v_n}$. gives 

* $v_n \in S$, this applies that $S-{v_n}$ is an optimal `WIS` on
    $V_{v_n,v_{n-1}}$.

* else $S$ is an `WIP` on $G-{v_n}$.


## Memoization ##

Without caching a recursive approach using the *optimal structure* still has an
**exponential time**. This is due to huge number of repetitions to recompute
already `WIS` for each nodes. The usual solution to avoid this repetition is
**memoization** wich saves the results of computed `WIS` in a cached vector.

\begin{equation}
\begin{cases}
A_0 = 0\\
A_1 = w_1\\
A_i = \max{\big( A_{i-1},A_{i-2}+w_i\big)}\\
\end{cases}
\end{equation}

