#ifndef _BBST_H_
#define _BBST_H_

#include "utils.h"
#include <string>
#include "record.h"

//gia to duplicate date sto dentro : oi komvoi exoun lista apo eggrafes me idio date
class reclist{
public:
  record * recptr; //deikths se eggrafh
  reclist * next; //o epomenos.

  reclist();
  reclist(record *);
  ~reclist();
  int insert_record(record * );
};


class BBST{
public:
  std::string * date; //deikths sthn hmeromhnia poy einai string
  reclist * list_of_records; //deikths sth lista eggrafwn. lista gt mporei na xoume panw apo ena me idia hmeromhnia
  BBST * left_child; //aristero paidi
  BBST * right_child; //deksi paidi

  BBST();
  BBST(record * ); //constructor basei eggrafhs
  ~BBST();
  int insert_record(record *);
  void print_contents();

};

#endif
