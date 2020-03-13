#ifndef _RECORD_HT_H_
#define _RECORD_HT_H_

#include "record.h"
#include "utils.hpp"
//H dikh moy domh gia thn apothhkeush twn eggrafwn. Me hash table exoume poly kalyterh xronikh polyplokothta ap oti me aplh lista.
//Na shmeiwthei pws autos o HT einai enas KLASSIKOS HT kai den akoloythei th morfologia twn disease kai country HT poy tha ftiaxtoun opws zhtaei h askhsh.

class record_HT_node{

  private:
    record_HT_node * next; //deikths ston epomeno komvo
    record * rec_ptr; //deikths sthn eggrafh
};


class record_HT{

  public:
    int size; //megethos pinaka. tha einai idio me kapoio apo ta h1, h2
    record_HT_node ** table; //ena array poy apoteleitai apo listes eggrafwn (buckets).
    record_HT(){}; //enas empty contrusctor
    record_HT(int ); //enas constructor me orisma size


};



#endif
