#include <functional>
#include <iostream>
#include "../include/HashTbl.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "../include/Account.h"
#endif

using namespace std;

int main(int argc, char const *argv[]){
	Account pessoa{11, "José", 3301, 45, 123123, 900.0};
	Account pessoa2{13, "Luan", 3456, 55, 127653, 920.0};

	ac::HashTbl<Account::AcctKey, Account, KeyHash, KeyEqual> * hash = new ac::HashTbl<Account::AcctKey, Account, KeyHash, KeyEqual>(90);
	hash->insert(pessoa.getKey(), pessoa);
	hash->insert(pessoa2 .getKey(), pessoa2);
	//hash->erase(pessoa2.getKey());
	//hash->clear();
	
	cout << hash << endl;
	return 0;
}