#include "Accout.h"

using namespace std;

template<class KeyType, class DataType>
class HashEntry{
public:
	HashEntry(KeyType k_, DataType d_): m_key( k_ ), m_data( d_ ){};
	KeyType m_key; //!< armazena a chave de um entry
	DataType m_data; //!< armazena a dado de um entry
};

struct KeyHash {
	size_t operator ()(const Account::AcctKey & k_) const{
		return std::hash<int>()(k_);
	}
};

struct KeyEqual {
	bool operator()(const Account::AcctKey & lhs_, const Account::AcctKey & rhs_) const{
		return lhs_ == rhs_ ;
	}
};

template<typename KeyType, typename DataType>
class HashTbl{
public:
	using AcctKey = int;
	using Entry = HashEntry<KeyType, DataType>;
	
	int qtdDivisores (int x ){
		int qtd = 0;
		for (int i = 1; i <= x; ++i){
			if(x%i==0) qtd++;
		}
		return qtd;
	}

	int ehPrimo (int x ){
		return qtdDivisores(x) == 2 ? 1 : 0;
	}
	
	HashTbl(size_t tbl_size_= DEFAULT_SIZE){
		if(!ehPrimo(tbl_size_)){
			while(!ehPrimo(tbl_size_)){
				tbl_size_++;
			}
		}
		
		m_size = tbl_size_;
	}
private:
	void rehash();
	unsigned int m_size;
	unsigned int m_count;

	forwardlist<Entry> * m_data_table;

	static const short DEFAULT_SIZE = 11;
};