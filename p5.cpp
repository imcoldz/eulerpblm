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
		for(int i=(int)primevec.size()-1; i>=0; --i){
			if(val%primevec[i]==0) return false;
		}
		return true;
	}
}

int main() {
	// your code goes here
	int k=20; //assert(k>=2);
	int target=1;
	unordered_map<int,int> compositionMap;
	for(int i=2; i<=k; ++i){
		//cout<<"judging value: "<<i<<endl;
		if(isPrime(i)){
			//cout<<"it is a prime."<<endl;
			target*=i;
			//cout<<"target updated to: "<<target<<endl;
			primevec.push_back(i);
		    compositionMap[i]=1;
		}else{
			int tmp=i;
			//cout<<"it is a non-prime."<<endl;
			//decompose each non-prime value and check whether you need to multiply a factor again
			for(int j=0; j<(int)primevec.size(); ++j){
				int cnt=0;
				int prime=primevec[j];
				while(i>1 && i%prime==0){
					i/=prime;
					cnt++;
				}
				//cout<<"has "<<cnt<<" number of factor: "<<primevec[j]<<endl;
				//cout<<"target has already included "<<compositionMap[prime]<<" number of this factor"<<endl;
				if(cnt>compositionMap[prime]){
					target*=pow(primevec[j], cnt-compositionMap[prime]);
					//cout<<"target updated to: "<<target<<endl;
					compositionMap[prime]=cnt;
				}
			}
			i=tmp;
		} 
	}
	cout<<target<<endl;
	return 0;
}
