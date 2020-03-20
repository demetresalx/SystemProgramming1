#include "myheap.h"
//https://stackoverflow.com/questions/31577866/c-convert-integer-to-binary-array
//SUNARTHSH METATROPHS INT SE ARRAY APO BITS
void int_to_bin_digit(unsigned int in, int count, int* out)
{
    /* assert: count <= sizeof(int)*CHAR_BIT */
    unsigned int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

//SUNARTHSEIS MAXHEAP
maxBinaryHeap::maxBinaryHeap(){
  root = NULL;
  number_of_nodes = 0;
}

maxBinaryHeap::maxBinaryHeap(std::string cat, int total){
  category = cat;
  root = NULL;
  number_of_nodes = 0;
  maxsize = total;
}

//destructor. TO DELETE STH RIZA LEITOURGEI SE OLO TO HEAP LOGW C++
maxBinaryHeap::~maxBinaryHeap(){
  delete root;
}

//gemizei to heap apo ena bbst
void maxBinaryHeap::insert_krousma(record * rec){
  if(root == NULL){ //prwto stoixeio sto heap
    root = new heapnode();
    if(category == "disease"){ //an eimaste gia topk_diseases
      root->cat_name = rec->get_diseaseID();
      root->krousmata += 1;
      return;
    }
    if(category == "country"){ //an eimaste gia topk_countries
      root->cat_name = rec->get_country();
      root->krousmata += 1;
      return;
    }
    number_of_nodes++; //anebainei o arithmos komvwn tou heap
  }
  else{ //yparxei riza
    //ftiaxnw bitpath. Kanw ton arithmo ths theshs binary kai 1 shmainei deksia, 0 aristera
    int * outta = new int[maxsize]; //megistos arithmos bits gia to path to last
    int_to_bin_digit(number_of_nodes+1, maxsize, outta); //twra to outta exei to bitpath poy prepei na akoloythhsw gia ton last kovmo
    
    delete[] outta;
  }

}


//SUNARTHSEIS HEAPNODE
//empty constr
heapnode::heapnode(){
  left = NULL;
  right = NULL;
  parent = NULL;
  krousmata = 0;
}

//constructor gia klhsh apo gonio
heapnode::heapnode(heapnode * par){
  left = NULL;
  right = NULL;
  parent = par;
  krousmata = 0;
}

//destructor. DOULEUEI ANADROMIKA LOGW DELETE POY STH C++ KALEI TOUS DESTRUCTORS
heapnode::~heapnode(){
  delete left;
  delete right;
  delete parent; //isws de xreiastei
}
