#include <vector>
#ifndef QUBIT_LAYOUT_H
#define QUBIT_LAYOUT_H

void display_gates(int circuit[][2], int num_gates);
void display_layout(const vector<int> &vi)
std::vector<int> get_qubits_bw_gate(std::vector<int> order, int C, int T);
bool is_overlapped(int circuit[][2], int k, vector<int> order);
std::vector<std::vector<int>> get_qubit_order_permutations(std::vector<std::vector<int>> P,
								  std::vector<int> initial_order);
#endif