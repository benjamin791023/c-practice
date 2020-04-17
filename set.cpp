#include <stdio.h>
#include <stdlib.h>

int findcollapsing(int *subset, int i){
	int root;
	for (root=i; subset[root] >=0; root=subset[root])
	
	while(i != root){
		int parange = subset[i];
		subset[i] = root;
		i = parent;
	}
	
	return parent;
}

int main(){
	return 0;
}
