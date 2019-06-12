#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	cout << " Hash (123) = " << hash<int>()(123) << endl ;
	cout << " Hash (-123) = " << hash<int>()(-123) << endl ;
	return 0;
}