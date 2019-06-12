#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "../include/Account.h"
#endif

using namespace std;

Account::Account(){
	this->id_account = -1;
	this->nome = "";
	this->banco = -1;
	this->agencia = -1;
	this->conta = -1;
	this->saldo = 0.0;
}

int Account::getId_account(){
	return this->id_account;
}
void Account::setId_account(int value){
	this->id_account = value;
}

int Account::getBanco(){
	return this->banco;
}
void Account::setBanco(int value){
	this->banco = value;
}

int Account::getAgencia(){
	return this->agencia;
}
void Account::setAgencia(int value){
	this->agencia = value;
}

int Account::getConta(){
	return this->conta;
}
void Account::setConta(int value){
	this->conta = value;
}

string Account::getNome(){
	return this->nome;
}
void Account::setNome(string value){
	this->nome = value;
}

double Account::getSaldo(){
	return this->saldo;
}
void Account::setSaldo(double value){
	this->saldo = value;
}