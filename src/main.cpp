#include <functional>
#include <iostream>
#include "../include/HashTbl.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "../include/Account.h"
#endif

using namespace std;

int main(int argc, char const *argv[]){

	Account pessoa();	
	sc::HashTbl<int, int, KeyHash, KeyEqual> * hash = new sc::HashTbl<int, int>(90);
	hash->insert(1, 2);

	return 0;
}