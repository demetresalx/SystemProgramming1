#ifndef _CD_HASHTABLE_H_
#define _CD_HASHTABLE_H_

#include <string>
#include "utils.h"
#include "record.h"

//o HT POU ZHTA H ASKHSH. Tha ftiaxtei enas gia country kai enas gia disease. H domh tous einai idia omws.
//apoteleitai apo ta ekshs antikeimena:

class block_entry{ //monh lista poy periexei ton katallhlo arithmo onomatwn (basei bucketsize) kai tous deiktes sta dendra
  public:
    std::string * dis_name_ptr; //deikths se string poy tha filoksenhsei to diseaseID h to country
    void * tree_ptr; //TREE NODE PTR
    int currval; //isws gia to currentpatients??

    block_entry();
    int insert_record(record * , std::string );
    ~block_entry();
};

class chain_node{ //komvos alusidas sto hash table
  public:
    int block_size; //auto poy tha prokypsei apo th diairesh me bucketsize
    block_entry * block; //dunamiko array block_size thesewn
    chain_node * next; //epomenos komvos

    chain_node(){};
    chain_node(int );
    bool insert_record(record *, std::string );
    void print_contents();
    ~chain_node();
};


class cdHashTable{ //o hash table
public:
  int size; //megethos pinaka (h1 h h2 analogws)
  int bucksize; //to bucketSize ths ekfwnhshs
  chain_node ** table; //ena dunamiko array poy periexei ta buckets

  cdHashTable(){};
  cdHashTable(int , int ); //constructor basei size kai bucketSize
  ~cdHashTable(){};
  void print_contents(); //ektypwnei auta p exei so far
  virtual int insert_record(record * ) {}; //to kathe derived class tha xeristei diaforetiko kleidi
};

class diseaseHashTable : public cdHashTable { //o hash table gia disease
public:
  diseaseHashTable(int, int);
  int insert_record(record * );
};

class countryHashTable : public cdHashTable { //o hash table gia disease
public:
  countryHashTable(int, int);
  int insert_record(record * );
};

#endif
