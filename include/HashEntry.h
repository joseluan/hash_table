template<class KeyType, class DataType>
class HashEntry{
public:
	HashEntry(KeyType k_, DataType d_): m_key( k_ ), m_data( d_ ){};
	KeyType m_key; //!< armazena a chave de um entry
	DataType m_data; //!< armazena a dado de um entry
};