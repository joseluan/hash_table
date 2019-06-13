#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Account.h"
#endif
#include <forward_list>

using namespace std;

template<class KeyType, class DataType>
class HashEntry{
public:
	HashEntry(KeyType k_, DataType d_): m_key( k_ ), m_data( d_ ){};
	KeyType m_key; //!< armazena a chave de um entry
	DataType m_data; //!< armazena a dado de um entry
};

struct KeyHash {
	size_t operator()(const Account::AcctKey & k_) const{
		return std::hash<int>()(k_);
	}
};

struct KeyEqual {
	bool operator()(const Account::AcctKey & lhs_, const Account::AcctKey & rhs_) const{
		return lhs_ == rhs_ ;
	}
};

namespace sc{
	template<typename KeyType, typename DataType,  class KeyHash , class KeyEqual>
	class HashTbl{
	public:
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

		~HashTbl(){
			auto it = m_data_table->cbegin();
			auto it2 = it++;
			while(it != m_data_table->cend()){
				delete it;
				it = it2;
				it2 = it++; 
			}
			delete m_data_table;
		}

		bool insert(const KeyType & key_, const DataType & data_item_){
			Entry new_entry(key_, data_item_);
			KeyHash hashFunc;
			KeyEqual equalFunc;

			auto end (hashFunc( key_ ) % m_size );
			m_data_table->push_front(new_entry);
			/*
			while(it != m_data_table->cend()){
				if( true == equalFunc((*it).m_key, new_entry.m_key)){
					cout << "DEU MERDA\n";
				}
			}
			*/
			
			return true;
		}
	private:
		void rehash();
		unsigned int m_size;
		unsigned int m_count;

		forward_list<Entry> * m_data_table;

		static const short DEFAULT_SIZE = 11;
	};
}