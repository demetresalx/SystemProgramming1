//MAIN ARXEIO. Apo edw trexei h efarmogh.
#include <iostream>
#include <string> //EPITREPETAI EIPWTHHKE STO PIAZZA
#include <fstream>
#include <stdlib.h> //atoi
#include <cstring> //strcpy gia ta pathings. genika oxi idiaitera
#include "record.h"
#include "record_HT.h"
#include "utils.h"
#include "cdHashTable.h"


int main(int argc, char *argv[]){

  //GIA TIS PARAMETROUS APO ARGC
  char dataset_path[256]; //to path tou patientRecordsFile poy tha parei apo to command line
  int diseaseHashtableNumOfEntries =0; //megethos disease hash table
  int countryHashtableNumOfEntries =0; //megethos countries hash table
  int bucketSize =0;
  for (int i = 0; i < argc; i++){
    if (strcmp("-p", argv[i]) == 0){
      strcpy(dataset_path, argv[i + 1]); //akoloythei to path
    }

    if (strcmp("-h1", argv[i]) == 0){
      diseaseHashtableNumOfEntries = atoi(argv[i + 1]); //akoloythei h timh
    }

    if (strcmp("-h2", argv[i]) == 0){
      countryHashtableNumOfEntries = atoi(argv[i + 1]); //akoloythei h timh
    }

    if (strcmp("-b", argv[i]) == 0){
      bucketSize = atoi(argv[i + 1]); //akoloythei h timh
    }

  } //telos for command line args
  record_HT records_htable(2*(diseaseHashtableNumOfEntries+countryHashtableNumOfEntries)); //o DIKOS MOU HT gia tis eggrafes basei recordID megethous h1+h2. KALUTEROS APO APLH LISTA
  diseaseHashTable diseases_htable(diseaseHashtableNumOfEntries, bucketSize); //O ZHTOUMENOS HT GIA DISEASE
  countryHashTable countries_htable(countryHashtableNumOfEntries, bucketSize); //O ZHTOUMENOS HT GIA COUNTRY
  //std::cout << "params are: " << dataset_path << " " << diseaseHashtableNumOfEntries << " " << countryHashtableNumOfEntries << " " << bucketSize << "\n";
  std::ifstream infile(dataset_path); //diabasma apo tis grammes tou arxeiou
  std::string line; //EPITREPETAI H STRING EIPAN STO PIAZZA
  while (std::getline(infile, line)){ //read file
    //https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c
    std::string const delims{ " \t," }; //delimiters einai ta: space,tab,comma. TELOS.
    size_t beg, pos = 0;
    int params_count =0;
    std::string record_parts[7]; //mia thesi gia kathe melos tou record wste na ta valw eukola se object meta
    while ((beg = line.find_first_not_of(delims, pos)) != std::string::npos){
        pos = line.find_first_of(delims, beg + 1);
        record_parts[params_count] = line.substr(beg, pos - beg);
        params_count++;
    }//telos while eksagwghs gnwrismatwn apo grammh
    if(params_count != 7) //problhmatiko input, prepei na akoloythei motivo ekfwnhshs. Tha faei skip auth h eggrafh
      continue;
    if(dates_compare(record_parts[5], record_parts[6]) != "smaller") //ean h entrydate einai megaluterh h ish ths exitdate
      continue;
    record * new_rec_ptr = new record(record_parts); //dhmiourgia eggrafhs
    if(records_htable.insert_record(new_rec_ptr) <0){ //brethhke diplotyph eggrafh. termatismos!
      std::cout << "brethhke diplotyph eggrafh. termatismos!\n";
      exit(EXIT_FAILURE);
    }
    diseases_htable.insert_record(new_rec_ptr); //eisagwgh ston dis HT
    countries_htable.insert_record(new_rec_ptr); //eisagwgh ston countries HT
    //std::cout << "\n";

  }//telos while read file
  //PAME GIA USER INPUT
  std::cout << "Data ready. Start giving commands!\n";
  while(getline(std::cin, line)){
    //getline(std::cin, line); //diabazei grammh apo keyboard
    if(line == "/exit")
      break; //olh h desmeumenh mnhmh apodesmeuetai mesw paneksupna sxediasmenwn destructors. Des se kathe class
    else{
      std::string requ[12]; //o arithmos orismatwn einai sugkekrimenos gia sugkekrimenes entoles opote de mas noiazei to orio
      std::stringstream check1(line);
      int ind=0; //arithmos orismatwn + tou onomatos entolhs
      while(getline(check1, requ[ind] , ' ')) { //DELIMITER EINAI TO KENO. TELOS
        ind++;
      }//telos while eksagwghs gnwrismatwn apo entolh
      if(requ[0] == "/globalDiseaseStats"){
          if(ind == 1){ //xwris ta proairetika date1 k date2
            diseases_htable.total_recs_per_cat();
            //countries_htable.total_recs_per_cat();
          }
          else if(ind ==3){ //me proairetika orismata date1 k date2
            if((dates_compare(requ[1], requ[2]) != "smaller") && (dates_compare(requ[1], requ[2]) != "equal") ){ //kakws orismeno date
              std::cout << "Date1 must be earlier or equal to Date2 or bad date\n";
              continue;
            }
            if((requ[1] == "-") || requ[2]== "-"){
              std::cout << "Date1 and Date2 can't be - , it's supposed to be an INTERVAL\n";
              continue;
            }
            diseases_htable.total_recs_per_cat(requ[1], requ[2]);
          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/diseaseFrequency"){
          if(ind == 4){ //xwris to proairetiko country
            if((dates_compare(requ[2], requ[3]) != "smaller") && (dates_compare(requ[2], requ[3]) != "equal") ){ //kakws orismeno date
              std::cout << "Date1 must be earlier or equal to Date2 or bad date\n";
              continue;
            }
            if((requ[2] == "-") || requ[3]== "-"){
              std::cout << "Date1 and Date2 can't be - , it's supposed to be an INTERVAL\n";
              continue;
            }
            diseases_htable.total_recs_for_cat( requ[1],requ[2], requ[3]);
          }
          else if(ind ==5){ //me proairetiko orisma country
            if((dates_compare(requ[2], requ[3]) != "smaller") && (dates_compare(requ[2], requ[3]) != "equal") ){ //kakws orismeno date
              std::cout << "Date1 must be earlier or equal to Date2 or bad date\n";
              continue;
            }
            if((requ[2] == "-") || requ[3]== "-"){
              std::cout << "Date1 and Date2 can't be - , it's supposed to be an INTERVAL\n";
              continue;
            }
            diseases_htable.total_recs_for_cat( requ[1],requ[2], requ[3], requ[4]);
          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/topk-Diseases"){
          if(ind == 3){ //xwris ta proairetika orismata date1 date2
            //doulitsa xwris dates
          }
          else if(ind ==5){ //me proairetika date1 + date2. De ginetai na yparxei to ena xwris to allo
            //me date1 k date2
          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/topk-Countries"){
          if(ind == 3){ //xwris ta proairetika orismata date1 date2
            //doulitsa xwris dates
          }
          else if(ind ==5){ //me proairetika date1 + date2. De ginetai na yparxei to ena xwris to allo
            //me date1 k date2
          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/insertPatientRecord"){
          if(ind == 7){ //xwris to proairetiko exitdate
            requ[7] = "-";
            std::string tat[7];
            for(unsigned int k=1; k<8; k++)
              tat[k-1] = requ[k];
            if(tat[5] == "-"){
              std::cout << "can't have - as entry date\n";
              continue;
            }
            if(is_date_ok(tat[5]) == false){
              std::cout << "bad date...\n";
              continue;
            }
            record * new_rec_ptr = new record(tat); //dhmiourgia eggrafhs
            if(records_htable.insert_record(new_rec_ptr) <0){ //brethhke diplotyph eggrafh. termatismos!
              std::cout << "brethhke diplotypo id eggrafhs. Den eisagw!\n";
              continue;
            }
            diseases_htable.insert_record(new_rec_ptr); //eisagwgh ston dis HT
            countries_htable.insert_record(new_rec_ptr); //eisagwgh ston countries HT

          }
          else if(ind == 8){ //me exitdate
            std::string tat[7];
            for(unsigned int k=1; k<8; k++)
              tat[k-1] = requ[k];
            if(dates_compare(tat[5], tat[6]) != "smaller"){ //kakws orismeno date
              std::cout << "entry date cannot be equal or later than exit date or bad date\n";
              continue;
            }
            record * new_rec_ptr = new record(tat); //dhmiourgia eggrafhs
            if(records_htable.insert_record(new_rec_ptr) <0){ //brethhke diplotyph eggrafh. termatismos!
              std::cout << "brethhke diplotypo id eggrafhs. Den eisagw!\n";
              continue;
            }
            diseases_htable.insert_record(new_rec_ptr); //eisagwgh ston dis HT
            countries_htable.insert_record(new_rec_ptr); //eisagwgh ston countries HT

          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/recordPatientExit"){
          if(ind == 3){
            if(requ[2] == "-"){
              std::cout << "You can't insert a - exit date. Doesn't make sense in the same record\n";
              continue;
            }
            if(is_date_ok(requ[2]) == false){
              std::cout << "bad date defined\n";
              continue;
            }
            bool wasinside = false;
            record * the_rec = records_htable.recordPatientExit(requ[1], requ[2], &wasinside);
            if( the_rec == NULL){
              std::cout << "Error:Date given equal or earlier than existing entryDate\n";
              std::cout << "OR record does not exist (yet).\n";
              continue;
            }
            if(wasinside == true){ //ean dhladh htan asthenhs ektos nosokomeiou hdh (non - se exitdate) mhn enhmerwseis metrhth
              diseases_htable.recordPatientExit(the_rec->get_diseaseID()); //enhmerwnei ton metrhth curr gia disease
              countries_htable.recordPatientExit(the_rec->get_country()); //enhmerwnei k to metrhth curr gia xwra
            }


          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else if(requ[0] == "/numCurrentPatients"){
          if(ind == 1){
            diseases_htable.numCurrentPatients("");
          }
          else if(ind == 2){ //to monadiko proairetiko orisma poy epitrepetai, to disease
            diseases_htable.numCurrentPatients(requ[1]);
          }
          else
            std::cout << "Lathos sta orismata. try again...\n";
      }
      else{
          std::cout << "kakws orismenh entolh. try again...\n";
      }//telos olwn ton ifs gia to poia kai pws einai h non-exit entolh
    }//telos else gia to an einai non-exit entolh
  }//telos while menu

  //records_htable.print_contents();
  //diseases_htable.print_contents();
  //countries_htable.print_contents();
  return 0;
}
