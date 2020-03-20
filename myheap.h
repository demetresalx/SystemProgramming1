#include "record.h"
//https://stackoverflow.com/questions/31577866/c-convert-integer-to-binary-array
//SUNARTHSH METATROPHS INT SE ARRAY APO BITS
void int_to_bin_digit(unsigned int , int , int* );

//mia klash gia komvo dentrou
class heapnode{
public:
  heapnode * left; //aristero paidi
  heapnode * right; //deksi paidi
  heapnode * parent; //goneas, isws de xreiazetai

  std::string cat_name; //onoma xwras h astheneias
  int krousmata; //arithmos krousmatwn


  heapnode();
  heapnode(heapnode*); //constructor apo gonio
  ~heapnode(); //destructor
};

//h klash moy heap gia ta erwthmata topk
class maxBinaryHeap{
public:
  int number_of_nodes; //arithmos komvwn poy exei mesa o heap
  heapnode * root;
  std::string category; //disease h country
  int maxsize; //iso me to total krousmata ths xwras/astheneias. De ginetai parapanw

  maxBinaryHeap();
  maxBinaryHeap(std::string , int ); //kathgoria kai total
  ~maxBinaryHeap();
  void insert_krousma(record *);
};

//swap periexomenou metaksu 2 heapnodes
void swap_nodes_info(heapnode *, heapnode *);
