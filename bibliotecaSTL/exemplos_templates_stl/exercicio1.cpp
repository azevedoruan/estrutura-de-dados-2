#include <vector>
#include <iostream>

using namespace std;

vector<int> coletar_pares(const vector<int>& v){
    vector<int> saida;
	for(auto i : v){
		if(i % 2 == 0){
			saida.push_back(i);
        	}
	}
	return saida;
}

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	vector<int> pares = coletar_pares(v);
	for(auto i : pares){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
