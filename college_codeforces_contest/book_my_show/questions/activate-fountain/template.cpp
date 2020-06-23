#include <bits/stdc++.h>
using namespace std;

/*********************** Template Begins ****************************/

/* Return an integer denoting the minimum number of fountains that must be activated */
int fountainActivation(vector<int> &locations)
{

}

/*********************** Template Ends ****************************/

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	cout << fountainActivation(a) << endl;
	return 0;
}
