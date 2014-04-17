/* Sum Square Difference
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <iostream>
using namespace std;

int sumSquareDiff(int start, int end){
	//assert(start>=0);
	//assert(end>=start);
	int val=0;
	int sum=0;
	for(int i=start; i<=end; ++i) sum+=i;
	for(int i=start; i<=end; ++i){
		val+=i*(sum-i);
	}
	return val;
}

int main() {
	// your code goes here
	int startVal=1;
	int endVal=100;
	cout<<sumSquareDiff(startVal, endVal)<<endl;
	return 0;
}
