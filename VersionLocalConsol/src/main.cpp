#include "../include/Controller.h"

using namespace std;

int main(int argc, char** argv){
	Controller c=Controller();
	for(int i=0;i<25;i++){
		cout << c.blockWord(i) << endl;
	}
	
	return 0;
}
