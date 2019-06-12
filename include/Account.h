#include <string>

using namespace std;

class Account{
	private:
		int id_account;
		string nome;
		int banco;
		int agencia;
		int conta;
		double saldo;
	public:
		Account();
		~Account();		

		int getId_account();
		void setId_account(int value);

		int getBanco();
		void setBanco(int value);

		int getAgencia();
		void setAgencia(int value);

		int getConta();
		void setConta(int value);

		string getNome();
		void setNome(string value);

		double getSaldo();
		void setSaldo(double value);
};