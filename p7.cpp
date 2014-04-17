/* 1001st prime number
 * What is the 10 001st prime number?
 */
#include <iostream>
#include <vector>
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
	int cnt=10001; //we assume it's larger than 2
	int i=1;
	int k=1;
	primevec.push_back(2);
	primevec.push_back(3);
	while(primevec.size()<cnt){
		i=6*(k++);
		if(isPrime(i-1)) primevec.push_back(i-1);
		if(isPrime(i+1)) primevec.push_back(i+1);
	}
	cout<<primevec[10000]<<endl;
	return 0;
}
