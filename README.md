# 1st System Programming Assignment 2020
**D. Alexandres, 1115201400006.**  
First (1st) assignment on UNIX system programming,  
*University of Athens, 2020.*

#ENTOLH METAGLWTTISHS

Αρχικά ελέγχονται τα ορίσματα που έδωσε ο χρήστης στη γραμμή εντολών και γίνονται οι κατάλληλες αναθέσεις.
Διαβάζονται οι εγγραφές από το αρχείο εισόδου και ισχύουν όσα λέει η εκφώνηση.

Απορρίπτονται αρχεία που έχουν εγγραφές με λιγότερα ή περισσότερα από 7 (επτά) γνωρίσματα:
1.recordID, 2.patientFirstName, 3.patientLastName, 4.diseaseID, 5.country, 6.entryDate, 7.exitDate (που μπορεί ασφαλώς να είναι παύλα.)
Οποιαδήποτε εγγραφή δεν ακολουθεί αυτό το μοτίβο αγνοείται.

Όποιο και να είναι το bucketSize, δε γίνεται ο αριθμός κόμβων σε blocks να είναι 0. Θα είναι τουλάχιστον 1.


ΕΞΩΤΕΡΙΚΕΣ ΑΝΑΦΟΡΕΣ
hash function : https://stackoverflow.com/questions/8317508/hash-function-for-a-string
tokenization of string : https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c
