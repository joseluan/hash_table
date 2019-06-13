/*! @file Account.h
    @brief Conta usada como base da tabela hash
*/
#include <string>

using namespace std;

class Account{
	private:
		int id_account; //!< armazena o id da conta
		string nome; //!< armazena o nome da conta
		int banco; //!< armazena o número do banco que está vinculado a conta
		int agencia; //!< armazena o número da agência que está vinculado a conta
		int conta; //!< armazena o número da conta no banco
		double saldo; //!< armazena o saldo da conta
	public:
		using AcctKey = int; //!< tipo de chave para a tabela hash
		
		/**
        * @brief fazendo a primeira função hash para a tabela hash
        * @return AccKey chave hash
        */
		AcctKey getKey(){
			return std::hash<AcctKey>()(conta);
		}		
		/**
        * @brief Contruttor sem argumentos
        */
		Account();
		/**
        * @brief Contruttor com todos os atrubutos
        */
		Account(int id_account, string nome, int banco, int agencia, int conta, double saldo);		

		//gets e sets
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