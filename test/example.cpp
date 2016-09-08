#include <iostream>
#include <string>
#include <algorithm>
#include "qubit_layout.cpp"

using namespace std;

int main()
{
	int num_gates;
	printf("%s\n", "Enter number of gates");
	cin >> num_gates;

	int num_qubits;
	printf("%s\n", "Enter number of qubits");
	cin >> num_qubits;

	//Consider Q as a 2D array defining the Quantum circuit in the reference [1].
	//Q[2] = {1,5} means that there is a controlled gate
	//between qubits 1 and 5 and the label for the gate is '2'. The
	//first element represents the control bit and the second element
	//represents the target bit.

	int Q[num_gates][2];
	for (int i=0; i<num_gates;i++)
	{
		printf("%s %d %s\n", "Enter the control and target qubit for gate :", i, "Example : 2 3");
		int C, T;
		cin >> C >> T;
		Q[i][0] = C;
		Q[i][1] = T;
	}
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
	printf("%s\n", "Enter the number of permutations to show");
	int perm;
	cin >> perm;

	printf("%s %d %s\n", "The permutation order selected for P[i] where i =",
					      perm, "is \n");

	display_layout(P[perm]);
	printf("%s\n", "Enter the label of gate to check for overlap \n");
	int k;
	cin >> k;
	printf("%s %d %s %d %s\n", "Testing if Gate :", k, "and Gate :", k+1,
					"are overlapped");

	printf("%s\n", "Enter the qubit layout from the permutations by specifying i for P[i] \n");
	int i;
	cin >> i;

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

  	bool test_overlapped = is_overlapped(Q, k, P[i]);
  	printf("%s %d\n", "Is overlapped : ", test_overlapped);

	return 0;
}