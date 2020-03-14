#ifndef _CD_HASHTABLE_H_
#define _CD_HASHTABLE_H_

#include <string>
#include "utils.h"
#include "record.h"

//o HT POU ZHTA H ASKHSH. Tha ftiaxtei enas gia country kai enas gia disease. H domh tous einai idia omws.
//apoteleitai apo ta ekshs antikeimena:

class block_entry{ //monh lista poy periexei ton katallhlo arithmo onomatwn (basei bucketsize) kai tous deiktes sta dendra
  public:
    std::string * str_ptr; //deikths se string poy tha filoksenhsei eite to diseaseID eite to country
    void * tree_ptr; //TREE NODE PTR
    int kati; //isws gia to currentpatients??

    block_entry(){};
    ~block_entry();
};

class chain_node{ //komvos alusidas sto hash table
  public:
    int block_size; //auto poy tha prokypsei apo th diairesh me bucketsize
    block_entry ** block; //dunamiko array block_size thesewn
    chain_node * next; //epomenos komvos

    chain_node(){};
    ~chain_node();
};


class cd_HashTable{ //o hash table
  int size; //megethos pinaka (h1 h h2 analogws)
  chain_node ** table; //ena dunamiko array poy periexei ta buckets

  cd_HashTable(){};
  cd_HashTable(int , int ); //constructor basei size kai bucketSize
  ~cd_HashTable();
};


#endif
