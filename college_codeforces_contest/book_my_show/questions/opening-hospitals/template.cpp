#include <bits/stdc++.h>
using namespace std;

/*********************** Template Begins ****************************/

int hospital(int city_nodes, vector<int> city_from, vector<int> city_to)
{

}
/*********************** Template Ends ****************************/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int city_nodes, edges;
	cin >> city_nodes >> edges;

	vector<int> city_from(edges), city_to(edges);

	for(int i = 0; i < edges; i++)
		cin >> city_from[i] >> city_to[i];

	cout << hospital(city_nodes, city_from, city_to) << endl;
	return 0;
}
