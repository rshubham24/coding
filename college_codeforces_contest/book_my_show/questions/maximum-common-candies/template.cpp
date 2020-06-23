#include<bits/stdc++.h>
using namespace std;

/*********************** Template Begins ****************************/

int countCandies(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{
	
}

/*********************** Template Ends ****************************/

int main()
{
	int friends_nodes;
	cin >> friends_nodes;

	int dim;
	cin >> dim;

	vector<int> friends_from(dim);
	for(auto &ele : friends_from)
		cin >> ele;

	cin >> dim;
	vector<int> friends_to(dim);
	for(auto &ele : friends_to)
		cin >> ele;

	cin >> dim;
	vector<int> friends_weight(dim);
	for(auto &ele : friends_weight)
		cin >> ele;

	cout << countCandies(friends_nodes, friends_from, friends_to, friends_weight);
	cout << endl;
	return 0;
}


