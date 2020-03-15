#include "bbst.h"

//GIA TO DENTRO
BBST::BBST(){
  date = NULL;
  list_of_records = NULL;
  left_child = NULL;
  right_child = NULL;
}

//constructor basei eggrafhs
BBST::BBST(record * rec){
  date = new std::string(rec->get_entryDate());
  list_of_records = new reclist(rec);

  left_child = NULL;
  right_child = NULL;
}

//SHMANTIKO. DIABASE TA SXOLIA MOY SE AUTON TON DESTRUCTOR
BBST::~BBST(){
  delete date; //apodesmeush tou xwrou gia to string poy eixame
  delete left_child; //Ean gia ena antikeimeno exei oristei destructor, H DELETE THA TON KALESEI
  delete right_child; //auto shmainei oti kathe paidi tha kalei tautoxrona tous destructors twn paidiwn tou kai olo to dentro apodesmeuetai epituxws
  //h eggrafh tha apodesmeutei apo th domh moy (aplos HT) opoy  kai anhkei
}





//komvos listas gia diplotypes hmeromhnies
reclist::reclist(){
  recptr = NULL;
  next = NULL;
}

reclist::reclist(record * rec){
  recptr = rec;
  next = NULL;
}

//destructor. H DELETE STHN C++ KALEI TOUS DESTRUCTORS ARA ME THN KLHSH THS DELETE GIA NEXT PAEI SE OLH TH LISTA
reclist::~reclist(){
  delete next;
}

//bazei eggrafh sth lista
int reclist::insert_record(record * rec){
  reclist * currptr = this;
  while(currptr->next != NULL) //paei sto teleutaio
    currptr = currptr->next ;
  currptr->next = new reclist(rec);

  return 0;
}
