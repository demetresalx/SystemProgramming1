#include "cdHashTable.h"

cdHashTable::cdHashTable(int sze, int bucketsize){
  size = sze;
  table = new chain_node *[size]; //ena dunamiko array apo deiktes se chain_node (buckets)
  for(unsigned int i=0; i<size; i++){
    table[i] = NULL; //arxika adeio olo
  }
  bucksize = bucketsize;
}

void cdHashTable::print_contents(){
  for(unsigned int i=0; i<size; i++){
    if(table[i] == NULL) //kenh alusida
      continue;
    else{
      chain_node * currptr = table[i];
      while(currptr!= NULL){ //paei sto teleutaio. ENDEIKTIKH EKTYPWSH. MONO MERIKA PEDIA ALLA MPORW KAI OLA
        std::cout << "block size is " << bucksize << "-";
        currptr->print_contents();
        std::cout << "\n\n";
        currptr = currptr->next ;
      }//telos while gia orizontia lista
    }//telos else
  }//telos for gia kathe alusida

}

//DISEASE
//derived parametrized constructor
diseaseHashTable::diseaseHashTable(int sze, int bucketsize) : cdHashTable(sze, bucketsize){
}

//h virtual gia disease
int diseaseHashTable::insert_record(record* rec){
  unsigned hval = hash_str(rec->get_diseaseID()); //hasharei to diseaseID
  hval = hval % size; //gia na pame sth swsth thesh pinaka

  if(table[hval] == NULL){ //ean den yparxei alusida ekei, th ftiaxnoyme
    table[hval] = new chain_node(bucksize);
    table[hval]->insert_record(rec, rec->get_diseaseID());
    return 0;
  }
  else{
    chain_node * currptr = table[hval];
    bool done = false;
    while(!done){ //prospathei na to valei se kapoio ths alusidas. to kathena koitaei ton pinaka tou
      done = currptr->insert_record(rec, rec->get_diseaseID());
      if((done==false)&&(currptr->next == NULL)){ //an den exei kataferei na th valei kai den exoume epomeno komvo, ftiaxnume k paei ekei.
        currptr->next = new chain_node(bucksize);
        currptr->next->insert_record(rec, rec->get_diseaseID());
        return 0;
      }//telos if
      currptr = currptr->next ;
    }//telos while done eisagwghs
  }//telos else

  return 0;
}



//COUNTRY
//derived parametrized constructor
countryHashTable::countryHashTable(int sze, int bucketsize) : cdHashTable(sze, bucketsize){
}

//h virtual gia country
int countryHashTable::insert_record(record* rec){
  unsigned hval = hash_str(rec->get_country()); //hasharei to country
  hval = hval % size; //gia na pame sth swsth thesh pinaka

  if(table[hval] == NULL){ //ean den yparxei alusida ekei, th ftiaxnoyme
    //table[hval] = new record_HT_node(rec);
  }
  return 0;
}


//CHAIN NODE
chain_node::chain_node(int sz){
  next = NULL;
  block_size = sz / sizeof(block_entry); //stathero megethos dioti exw deiktes sth domh block entry
  if(block_size < 1)
    block_size = 1; //toulaxiston ena element mesa
  block = new block_entry[block_size]; //toses theseis oses leei h ekfwnhsh
}

bool chain_node::insert_record(record* rec, std::string key){
  for(unsigned int i=0; i<block_size; i++){
    if(block[i].dis_name_ptr == NULL){ //einai h 1h adeia thesh, valto ekei
      block[i].insert_record(rec, key);
      return true; //komple
    }
    if( *(block[i].dis_name_ptr) == rec->get_diseaseID() ){ //h astheneia yparxei. proxwrame edw.
      block[i].insert_record(rec, key);
      return true; //komple
    }
  }
  return false;
}

void chain_node::print_contents(){
  std::cout << "chain blocksz is " << block_size << "/";
  for(unsigned int i=0; i<block_size; i++){
    if(block[i].dis_name_ptr == NULL)
      continue;
    std::cout << *(block[i].dis_name_ptr) << " " << block[i].currval << "\n";
  }
}


//BLOCK ENTRY
block_entry::block_entry(){
  dis_name_ptr = NULL;
  tree_ptr = NULL;
  currval =0;
}

int block_entry::insert_record(record * rec, std::string key){
  dis_name_ptr = new std::string(key);
  tree_ptr = NULL; //allazei s ligo
  currval++;
  return 0;
}
