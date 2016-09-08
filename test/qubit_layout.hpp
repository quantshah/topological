#include <vector>
#ifndef QUBIT_LAYOUT
#define QUBIT_LAYOUT

void display_gates(int circuit[][2], int num_gates);
void display_layout(const std::vector<int> vi);
std::vector<int> get_qubits_bw_gate(std::vector<int> order, int C, int T);
bool is_overlapped(int circuit[][2], int k, std::vector<int> order);
std::vector<std::vector<int>> get_qubit_order_permutations(std::vector<std::vector<int>> P,
								  std::vector<int> initial_order);

#endif