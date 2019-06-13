/*! @file HashTbl.h
    @brief Tabela Hash, mal implementada
*/
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

namespace ac{
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
			if(m_count == m_size) return false;

			Entry new_entry(key_, data_item_);
			KeyHash hashFunc;
			KeyEqual equalFunc;

			auto end (hashFunc( key_ ) % m_size );

			auto it = m_data_table.begin();			
			
			while(it != m_data_table.end()){
				if( true == equalFunc((*it).m_key, new_entry.m_key)){
					(*it).m_data = data_item_;
				}
				it++;
			}

			m_count++;
			
			m_data_table.push_front(new_entry);
			
			return true;
		}

		bool erase(const KeyType & k_){
			KeyHash hashFunc;
			KeyEqual equalFunc;
			//auto end (hashFunc( k_ ) % m_size );
			auto it = m_data_table.begin();
			auto it2 = m_data_table.before_begin();			
					
			while(it2 != m_data_table.end()){
				if( true == equalFunc((*it2).m_key, k_ )){
					m_data_table.erase_after(it);
					m_count--;
					return true;
				}
				it = it2;
				it2++;
			}

			return false;
		}

		void clear(void){
			while(!m_data_table.empty()){
				m_data_table.pop_front();
			}
			m_count = 0;
		}

		bool empty(void) const{
			return m_count == 0;
		}

		size_t size(void) const{
			return m_count;
		}

		DataType & at(const KeyType & k_ ){
			KeyHash hashFunc;
			KeyEqual equalFunc;

			auto end (hashFunc( k_ ) % m_size );

			auto it = m_data_table.begin();			
			
			while(it != m_data_table.end()){
				if( true == equalFunc((*it).m_key, k_ )){
					return (*it).m_data;
				}
				it++;
			}
		}

		DataType & operator[](const KeyType & k_ ){
			KeyHash hashFunc;
			KeyEqual equalFunc;

			auto end (hashFunc( k_ ) % m_size );

			auto it = m_data_table.begin();			
			
			while(it != m_data_table.end()){
				if( true == equalFunc((*it).m_key, k_ )){
					return (*it).m_data;
				}
				it++;
			}
		}

		friend std::ostream & operator<<(std::ostream & os, const HashTbl & hash){
			auto it = hash.begin();			
			os << "[ ";
			while(it != hash.end()){
				os << (*it).m_data.getNome();
				os << " ";
				it++;
			}
			os << "]";
		}

	private:
		void rehash();
		unsigned int m_size;
		unsigned int m_count;

		forward_list<Entry> m_data_table;

		static const short DEFAULT_SIZE = 11;
	};
}