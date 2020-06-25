#include <bits/stdc++.h>
using namespace std;

/*************************** Template Begins ******************************/

/* ### READ-ONLY PART ### */
double pizzaDelivery(int input1, int input2, int** input3)
/* ### READ-ONLY PART ### */
{
}

/*************************** Template Ends ******************************/

int main()
{
	int input1, input2;
	
	int** input3;

	const int max_n = 1e3 + 3;
	input3 = (int**)malloc(max_n*sizeof(int*));

	for(int i = 0; i < max_n; i++)
		input3[i] = (int*)malloc(2*sizeof(int));

	scanf("%d %d", &input1, &input2);
	for(int i = 0; i < input2; i++)
	{
		scanf("%d %d", &input3[i][0], &input3[i][1]);
	}

	double res = pizzaDelivery(input1, input2, input3);
	printf("%lf\n", res);

	return 0;
}
