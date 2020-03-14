#include "record_HT.h"

//constructor gia node basei deikth se eggrafh
record_HT_node::record_HT_node(record * rec){
  next = NULL;
  rec_ptr = rec;
}

record_HT_node::~record_HT_node(){
  //destructor isws to ftiaksw
}

//constructor gia HT basei size
record_HT::record_HT(int si){
  size = si;
  table = new record_HT_node *[size]; //ena dunamiko array apo deiktes se ht_nodes (buckets)
  for(unsigned int i=0; i<size; i++){
    table[i] = NULL; //arxika adeio olo
  }
}
record_HT::~record_HT(){
  //destructor isws to ftiaksw
}

//vazei record sto HT. HASHING BASEI ID
int record_HT::insert_record(record * rec){
  unsigned hval = hash_str(rec->get_recordID()); //hasharei to recordID
  hval = hval % size; //gia na pame sth swsth thesh pinaka

  if(table[hval] == NULL){ //ean den yparxei alusida ekei, th ftiaxnoyme
    table[hval] = new record_HT_node(rec);
  }
  else{ //yparxei alusida, pame sto telos ENW KOITAZOUME OTI DEN YPARXEI IDIO ID
    record_HT_node * currptr = table[hval];
    while(currptr->next != NULL){ //paei sto teleutaio
      if(currptr->rec_ptr->get_recordID() == rec->get_recordID()) //brethhke idio id, abort mission!
        return -1;
      currptr = currptr->next ;
    }
    if(currptr->rec_ptr->get_recordID() == rec->get_recordID()) //brethhke idio id, abort mission!
      return -1;
    currptr->next = new record_HT_node(rec);
  }
  return 0; //egine ok, return 0

}

//sunarthsh ektypwshs
void record_HT::print_contents(){
  for(unsigned int i=0; i<size; i++){
    if(table[i] == NULL) //kenh alusida
      continue;
    else{
      record_HT_node * currptr = table[i];
      while(currptr!= NULL){ //paei sto teleutaio. ENDEIKTIKH EKTYPWSH. MONO MERIKA PEDIA ALLA MPORW KAI OLA
        std::cout << currptr->rec_ptr->get_recordID() << " " << currptr->rec_ptr->get_diseaseID() << " " << currptr->rec_ptr->get_patientFirstName() << "\n";
        currptr = currptr->next ;
      }//telos while gia orizontia lista
    }//telos else
  }//telos for gia kathe alusida
}//telos sunarthshs