#include <iostream>
#include <string>
#include <algorithm>
#include "qubit_layout.cpp"

using namespace std;

int main()
{
	int num_gates = 8;
	int num_qubits = 9;

	//Consider Q as a 2D array defining the Quantum circuit in the reference [1].
	//Q[2] = {1,5} means that there is a controlled gate
	//between qubits 1 and 5 and the label for the gate is '2'. The
	//first element represents the control bit and the second element
	//represents the target bit.

	int Q[num_gates][2] = {{9,7}, {8,2}, {1,5}, {3,4},
								{3,9}, {6,2}, {4,7}, {5,1}};
	display_gates(Q, num_gates);

	//Consider P as a 2D array which holds the qubit orders. The first element of
	//P will be the intial qubit order {0,1,2,3,4,...} and later elements will
	//have all other permutations. 

	vector<vector<int>> P;
	vector<int> initial_order;

	for (int i=1;i<=num_qubits; i++)
	{
			initial_order.push_back(i);
	}
	printf("%s\n", "Initial order of qubits" );
	display_layout(initial_order);
	P = get_qubit_order_permutations(P, initial_order);
	int i =1000;

	int k = 1;

	printf("%s %d %s %d %s\n", "Testing if Gate :", k, "and Gate :", k+1,
					"are overlapped");

	int C1 = Q[k][0];
	int T1 = Q[k][1];

	int C2 = Q[k+1][0];
	int T2 = Q[k+1][1];

	std::vector<int> gates_bw_C1_T1 = get_qubits_bw_gate(P[i], C1, T1 );
	std::vector<int> gates_bw_C2_T2 = get_qubits_bw_gate(P[i], C2, T2 );

	printf("%s %d %s %d %s\n", "Qubits between ", C1, "and", T1, "are" );
	display_layout(gates_bw_C1_T1);

	printf("%s %d %s %d %s\n", "Qubits between ", C2, "and", T2, "are" );
	display_layout(gates_bw_C2_T2);

	printf("%s %d %s\n", "The order selected for P[i] where i =", i, "is \n");
	display_layout(P[i]);

  	bool test_overlapped = is_overlapped(Q, k, P[i]);
  	printf("%s %d\n", "Is overlapped : ", test_overlapped);

	return 0;
}