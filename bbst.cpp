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
  delete list_of_records; //svhnei th lista me idio tropo giati kathe komvos ths exei destructor
  delete left_child; //Ean gia ena antikeimeno exei oristei destructor, H DELETE THA TON KALESEI
  delete right_child; //auto shmainei oti kathe paidi tha kalei tautoxrona tous destructors twn paidiwn tou kai olo to dentro apodesmeuetai epituxws
  //h eggrafh tha apodesmeutei apo th domh moy (aplos HT) opoy  kai anhkei
}


//eisagei eggrafh sto dentro. den exoume data duplication afou milame gia deikth sthn arxikh eggrafh poy brisketai sth dikh moy domh aplou HT
int BBST::insert_record(record* rec){
  //std::cout << dates_compare(rec->get_entryDate() , *date);
  if(dates_compare(rec->get_entryDate() , *date) == "equal"){ //ean h hmeromhnia ths eggrafhs einai ish me tou komvou
    //std::cout << "brhka idio date";
    list_of_records->insert_record(rec); //valth sth lista tou komvou
    return 0;
  }//telos if gia hmeromhnia
  else if(dates_compare(rec->get_entryDate() , *date) == "bigger"){ //ean h hmeromhnia ths eggrafhs einai megaluterh ap tou komvou
    if(right_child == NULL){ //prepei na pame deksia kai den yparxei deksi paidi. to ftiaxnoume k paei ekei
      right_child = new BBST(rec);
      return 0;
    }
    else //yparxei deksi paidi, eksetazoume apo kei kai ustera
      right_child->insert_record(rec);

  }//telos else if gia hmeromhnia
  else{ //hmeromhnia eggrafhs mikroterh tou komvou
    if(left_child == NULL){ //prepei na pame aristera kai den yparxei deksi paidi. to ftiaxnoume k paei ekei
      left_child = new BBST(rec);
      return 0;
    }
    else //yparxei aristero paidi, eksetazoume apo kei kai ustera
      left_child->insert_record(rec);
  }//telos else gia hmeromhnia

}//telos sunarthshs

void BBST::print_contents(){
  std::cout << "eimai komvos dentrou, exw date: " << *date << "\n";
  list_of_records->print_contents();
  if(left_child != NULL)
    left_child->print_contents();
  if(right_child != NULL)
    right_child->print_contents();
}




//komvos listas gia diplotypes hmeromhnies
reclist::reclist(){
  recptr = NULL;
  next = NULL;
}

reclist::reclist(record * rec){
  //std::cout << "yparxww kai bazww " << rec->get_patientFirstName();
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

void reclist::print_contents(){
  std::cout << "\t eimai h lista ston komvo t dentrou kai exw ta: ";
  reclist * currptr = this;
  while(currptr != NULL){ //paei mexri to telos
    std::cout << currptr->recptr->get_patientFirstName() << " ";
    currptr = currptr->next ;
  }//telos while gia next
  std::cout << "\n";
}
