## C++ code for optimization of topological quantum circuits

This an attempt to implement the optimization routine from the poster on
**"Qubit Arrangement Problems for Topological Quantum Computation"** authored
by Shigeru Yamashita, Shinnosuke Hiratsuka, Simon Devitt and Kae Nemoto.

The poster describing the algorithm can be found [here](https://www.imsc.res.in/~aqis13/extended/posters/shigeru_yamashita_81.pdf).

This is a work in progress. `examples/main.cpp` has a basic example which declares a quantum circuit **Q**, generates a permutation of qubit order layouts from a given initial order **P** and tests whether two gates are ` overlapped` or `non-overlapped` based on a particular order **P[i]**. Currently, the functions `display_gates`, `display_layout`, `is_overlapped`, `get_permutations` and `get_qubits_bw_gate` are implemented.

Further work includes finding a good library for Graphs to find maximum `clique according to the specified algorithm to get an optimized order **P**.
