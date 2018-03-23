//RJ VARONA
//last modified 03/19/18
// hashTable Assignment

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip> 
#include <queue>
#include <math.h>

using namespace std;

class HashNode    
{   
    private:

    string word;                                                // the node contains a word
    HashNode *next = nullptr;                                   //the pointer to the next node in the linked list
    
    
    public:
    string getString(){                                         //get string
        return word;
    }
    HashNode* returnNext(){
        return this->next;
    }
    void setNext(){
        this->next = next;
    }
    void setString(){
        this->word = word;
    }
    
};
class hashTable
{
    HashNode **nodeVector; 
    //double pointer for the array thingy
    string wordy;
    //string filename for reading input
    string filenamez;
    //int for getting tablesize
    int tablesize;
    //vector the table that creates table with linked nodes to each other yeah
    vector<vector<string>> theTable;            
 public:                            


    //constructor
    hashTable(int size, string filename)                       //creates hashtable with size and filename
    {
        vector<vector<string>> hashNoodle(size);                //hashNoodle is my hash table
        hashNoodle = theTable;                                  //table now has size
        this->filenamez = filename;                             //filename
        this->tablesize = size;                                 //tablesize
        
        // }
    }


    unsigned hashFunc(string index){                                 //maps string to a table   shows index of the word to allocate     
        int position = 0;
        int returnedPosition = 0;
         for(unsigned i = 0; i < index.length(); i++){
             char chz = index[i];
            position = position + chz;
         }
        returnedPosition = position % tablesize;        
        position = 0;
        return returnedPosition;

    }                                            
    bool remove(string word){                                       //return true if string there and false if isnt 
        unsigned positioni =  hashFunc(word);                            //position
       HashNode *pointer =  theTable[positioni];                        //fix later

        if (pointer->getString() == word)
        {
            pointer->setString() = nullptr;  
        }
        else
        {
        while(pointer != nullptr){
            pointer = pointer->setNext;
            if(pointer->getString() == word){
                pointer->setString() = nullptr; 
                return true;
            }
        }
        return false;
        }  
    }                                 
    bool insert(string word){                                   //if (insert) return true else false
       unsigned positioni =  hashFunc(word);                            //position
       HashNode *pointer =  theTable[positioni];                        //fix later

        if (pointer->getString() == nullptr)
        {
            pointer->setString() = word;  
        }
        else
        {

        while(pointer != nullptr){
            pointer = pointer->setNext();
            if(pointer){
                pointer->setString() = word; 
                return true;
            }
        }
        
        return false;
        }                                  
   
   
   
    bool contains(string word)
    {                                       //if word is there return true else return false
       unsigned positioni =  hashFunc(word);                            //position
       HashNode *pointer =  theTable[positioni];                        //fix later   

        while(pointer != nullptr){
            if(pointer->getString() == "")
                return true;
        }
        return false;                                                 //break loop return false
    }                               

};

int main()
{
    hashTable tablez(11,"first");                                           //create hash table
    string wordFind;                                                        //string to findM
    while(wordFind != ".")
    {
        cin >> wordFind;
       int testPos;
        for(unsigned i = 0; i < wordFind.length(); i++){                     //with the Mod add it to the vector
            char chz = wordFind[i];
            testPos = testPos + chz;
        }
        cout << testPos << '\n';
        testPos = 0;
        if (tablez.insert(wordFind))
        {
            cout << "*\n";
        }       
        else
        {
            cout << "modify later to make the corrections" << '\n';
        }
    }
}