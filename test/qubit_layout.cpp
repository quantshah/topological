/*
 * qubit_layout : An attempt to implement an optimization routine
 * for topological quantum circuits following the algorithm in the reference
 *
 * [1] https://www.imsc.res.in/~aqis13/extended/posters/shigeru_yamashita_81.pdf
 * 
 * Author : Shahnawaz Ahmed 
 * Email : shahnawaz.ahmed95@gmail.com
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Display a given circuit by specifying the gate label, control and target qubits.
 */
void display_gates(int circuit[][2], int num_gates)
{
	for (int k = 0; k < num_gates; k++)
	{
  		printf("%s %d %s %d %s %d\n",
  			"Gate Label: ", k, "Control qubit: ", circuit[k][0],
  			"Target qubit: ", circuit[k][1]);
  	}
}
/*
 * Display a vector. This is used to print a particular qubit order.
 */
void display_layout(const vector<int> &vi)
{
	for(size_t i = 0; i < vi.size(); ++i)
		cout << vi[i] << endl;
	cout << endl;
}
/*
 * Returns a vector with the qubit labels between control qubit C 
 * and target qubit T from the given order.
 */
vector<int> get_qubits_bw_gate(vector<int> order, int C, int T)
{
	vector<int>::iterator it;
    it = find(order.begin(), order.end(), C);
    int start = distance(order.begin(), it);

    it = find(order.begin(), order.end(), T);
    int end = distance(order.begin(), it);

    vector<int> v;

    if (start < end)
    {
    	for (int i = start + 1; i < end; i++)
    	{
    		v.push_back(order[i]);
    	}
    }
    else
    {
    	for (int i=end+1; i<start;i++)
    	{
    		v.push_back(order[i]);
    	}	    	
    }
    return v;
}
/**
 * Function to check whether gates k and k+1 are overlapping using the
 * order layout `order`.
*/
bool is_overlapped(int circuit[][2], int k, vector<int> order)
{
	//Get the control and target qubits for both consequtive gates
	int C1 = circuit[k][0];
	int T1 = circuit[k][1];

	int C2 = circuit[k+1][0];
	int T2 = circuit[k+1][1];

	std::vector<int> gates_bw_C1_T1 = get_qubits_bw_gate(order, C1, T1 );
	std::vector<int> gates_bw_C2_T2 = get_qubits_bw_gate(order, C2, T2 );

	for (int i=0; i<gates_bw_C1_T1.size()+1; i++)
	{
		for (int j=0; j<gates_bw_C2_T2.size()+1; j++)
		{	
			if (gates_bw_C1_T1[i] == gates_bw_C2_T2[j])
				return false;
		}
	}
	return true;
}
/**
 * Function to get all permutations of qubits. This is the set P.
*/
vector<vector<int>> get_qubit_order_permutations(vector<vector<int>> P,
	                                             vector<int> initial_order)
{
	while(next_permutation(initial_order.begin(),initial_order.end())){
		P.push_back(initial_order);
	}
	return P;
}