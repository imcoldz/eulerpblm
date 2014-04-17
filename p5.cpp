/* Smallest Multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

vector<int> primevec;

//we are assuming that primevec is inserting prime values in ascending order
bool isPrime(int val){
	if(val<2) return false;
	if(primevec.empty()) return true;
	else{
		int highbound=sqrt(val)+1;
		for(int i=0; i<primevec.size(); ++i){
			if(primevec[i]>highbound) break;
			if(val%primevec[i]==0) return false;
		}
		return true;
	}
}

int main() {
	// your code goes here
	int k=20; //assert(k>=2);
	int target=1;
	for(int i=2; i<=k; ++i){
		//cout<<"judging value: "<<i<<endl;
		if(isPrime(i)){
			//cout<<"it is a prime."<<endl;
			int exp=log(k)/log(i);
			target*=pow(i, exp);
			//cout<<"target updated to: "<<target<<endl;
			primevec.push_back(i);
		}
	}
	cout<<target<<endl;
	return 0;
}
