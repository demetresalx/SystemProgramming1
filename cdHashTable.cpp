#include "cdHashTable.h"

cdHashTable::cdHashTable(int sze, int bucketsize){
  size = sze;
  table = new chain_node *[size]; //ena dunamiko array apo deiktes se chain_node (buckets)
  for(unsigned int i=0; i<size; i++){
    table[i] = NULL; //arxika adeio olo
  }
  
}


//derived parametrized constructor
diseaseHashTable::diseaseHashTable(int sze, int bucketsize) : cdHashTable(sze, bucketsize){
}
//h virtual gia disease
int diseaseHashTable::insert_record(record* rec){
  unsigned hval = hash_str(rec->get_diseaseID()); //hasharei to diseaseID
  hval = hval % size; //gia na pame sth swsth thesh pinaka

  if(table[hval] == NULL){ //ean den yparxei alusida ekei, th ftiaxnoyme
    //table[hval] = new record_HT_node(rec);
  }
  return 0;
}


//derived parametrized constructor
countryHashTable::countryHashTable(int sze, int bucketsize) : cdHashTable(sze, bucketsize){
}
//h virtual gia country
int countryHashTable::insert_record(record* rec){
  unsigned hval = hash_str(rec->get_diseaseID()); //hasharei to diseaseID
  hval = hval % size; //gia na pame sth swsth thesh pinaka

  if(table[hval] == NULL){ //ean den yparxei alusida ekei, th ftiaxnoyme
    //table[hval] = new record_HT_node(rec);
  }
  return 0;
}
