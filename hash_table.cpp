/*
Student Name: Sofiyan Monga
Date: 11/4/2022
=======================
ECE 2035 Project 2-1:
=======================
This file provides definition for the structs and functions declared in the
header file. It also contains helper functions that are not accessible from
outside of the file.

FOR FULL CREDIT, BE SURE TO TRY MULTIPLE TEST CASES and DOCUMENT YOUR CODE.

===================================
Naming conventions in this file:
===================================
1. All struct names use camel case where the first letter is capitalized.
    e.g. "HashTable", or "HashTableEntry"

2. Variable names with a preceding underscore "_" will not be called directly.
    e.g. "_HashTable", "_HashTableEntry"

    Recall that in C, we have to type "struct" together with the name of the struct
    in order to initialize a new variable. To avoid this, in hash_table.h
    we use typedef to provide new "nicknames" for "struct _HashTable" and
    "struct _HashTableEntry". As a result, we can create new struct variables
    by just using:
        - "HashTable myNewTable;"
    or
        - "HashTableEntry myNewHashTableEntry;"
    
    The preceding underscore "_" simply provides a distinction between the names
    of the actual struct defition and the "nicknames" that we use to initialize
    new structs.
    [See Hidden Definitions section for more information.]

3. Functions, their local variables and arguments are named with camel case, where
    the first letter is lower-case.
    e.g. "createHashTable" is a function. One of its arguments is "numBuckets".
        It also has a local variable called "newTable".

4. The name of a struct member is divided by using underscores "_". This serves
    as a distinction between function local variables and struct members.
    e.g. "num_buckets" is a member of "HashTable".
*/


/****************************************************************************
 * Include the Public Interface
 *
 * By including the public interface at the top of the file, the compiler can
 * enforce that the function declarations in the the header are not in
 * conflict with the definitions in the file. This is not a guarantee of
 * correctness, but it is better than nothing!
 ***************************************************************************/
#include "hash_table.h"

/****************************************************************************
 * Include other private dependencies
 *
 * These other modules are used in the implementation of the hash table module,
 * but are not required by users of the hash table.
 ***************************************************************************/
#include <stdlib.h> // For malloc and free
#include <stdio.h>  // For printf

/****************************************************************************
 * Hidden Definitions
 *
 * These definitions are not available outside of this file. However, because
 * the are forward declared in hash_table.h, the type names are
 * available everywhere and user code can hold pointers to these structs.
 ***************************************************************************/
/**
 * This structure represents an a hash table.
 * Use "HashTable" instead when you are creating a new variable. [See top comments]
 */
struct _HashTable
{
    /** The array of pointers to the head of a singly linked list, whose nodes
        are HashTableEntry objects */
    HashTableEntry **buckets;

    /** The hash function pointer */
    HashFunction hash;

    /** The number of buckets in the hash table */
    unsigned int num_buckets;
};

/**
 * This structure represents a hash table entry.
 * Use "HashTableEntry" instead when you are creating a new variable. [See top comments]
 */
struct _HashTableEntry
{
    /** The key for the hash table entry */
    unsigned int key;

    /** The value associated with this hash table entry */
    void *value;

    /**
     * A pointer pointing to the next hash table entry
     * NULL means there is no next entry (i.e. this is the tail)
     */
    HashTableEntry *next;
};

/****************************************************************************
 * Private Functions
 *
 * These functions are not available outside of this file, since they are not
 * declared in hash_table.h.
 ***************************************************************************/
/**
 * createHashTableEntry
 *
 * Helper function that creates a hash table entry by allocating memory for it on
 * the heap. It initializes the entry with key and value, initialize pointer to
 * the next entry as NULL, and return the pointer to this hash table entry.
 *
 * @param key The key corresponds to the hash table entry
 * @param value The value stored in the hash table entry
 * @return The pointer to the hash table entry
 */
static HashTableEntry *createHashTableEntry(unsigned int key, void *value)
{
    // TODO: Implement
    HashTableEntry *newEntry = (HashTableEntry *)malloc(sizeof(HashTableEntry));    //allocate memory for new HashTableEntry
    newEntry->value = value;                                                        //set value of new Entry to value passed in
    newEntry->key = key;                                                            //set key of new Entry to value passed in
    newEntry->next = NULL;                                                          //set next of new Entry to NULL
    return newEntry;                                                                //return the new Entry created to caller
}

/**
 * findItem
 *
 * Helper function that checks whether there exists the hash table entry that
 * contains a specific key.
 *
 * @param hashTable The pointer to the hash table.
 * @param key The key corresponds to the hash table entry
 * @return The pointer to the hash table entry, or NULL if key does not exist
 */
static HashTableEntry *findItem(HashTable *hashTable, unsigned int key)
{
    // TODO: Implement
    unsigned int bucketNum = hashTable->hash(key);                  //use hashFunction of hashTable to find which LL the key is allocated to
    HashTableEntry *thisBucket = hashTable->buckets[bucketNum];     //create entry that is the first bucket in the LL chain
    
    while (thisBucket != NULL) {                                    
        unsigned int checkKey = thisBucket->key;                    //create unsigned int for the key of current bucket
        if (checkKey == key) {                                      //check if the key is the one we are looking for 
            return thisBucket;                                      //return pointer to bucket of key that we are looking for
        }
        thisBucket = thisBucket->next;                              //if key not found move onto next bucket in LL chain
    }
    return NULL;                                                    //return NULL if no buckets have key passed in
}

/****************************************************************************
 * Public Interface Functions
 *
 * These functions implement the public interface as specified in the header
 * file, and make use of the private functions and hidden definitions in the
 * above sections.
 ****************************************************************************/
// The createHashTable is provided for you as a starting point.
HashTable *createHashTable(HashFunction hashFunction, unsigned int numBuckets)
{
    // The hash table has to contain at least one bucket. Exit gracefully if
    // this condition is not met.
    if (numBuckets == 0)
    {
        printf("Hash table has to contain at least 1 bucket...\n");
        exit(1);
    }

    // Allocate memory for the new HashTable struct on heap.
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));

    // Initialize the components of the new HashTable struct.
    newTable->hash = hashFunction;
    newTable->num_buckets = numBuckets;
    newTable->buckets = (HashTableEntry **)malloc(numBuckets * sizeof(HashTableEntry *));

    // As the new buckets are empty, init each bucket as NULL.
    unsigned int i;
    for (i = 0; i < numBuckets; ++i)
    {
        newTable->buckets[i] = NULL;
    }

    // Return the new HashTable struct.
    return newTable;
}

void destroyHashTable(HashTable *hashTable)
{
    // TODO: Implement
    // 1. Loop through each bucket of the hash table to remove all items.
    //      1a. set temp to be the first entry of the ith bucket
    //      1b. delete all entries
       
    // 2. Free buckets
    
    // 3. Free hash table
    HashTableEntry *nxt, *tmp;                          //create local Entries for use in function
    for (int i = 0; i < hashTable->num_buckets; i++) {  //loop for number of LLs in the hash table
        tmp = hashTable->buckets[i];                    //set tmp to first bucket in the ith LL of the table
        while(tmp != NULL) {                            //keep looping whilst there are entries in the current LL 
            nxt = tmp->next;                            //save the next entry before deleting current entry
            free(tmp->value);                           //free the memory for current entry's value
            free(tmp);                                  //free the memory for the current entry
            tmp = nxt;                                  //set current entry pointer to the next bucket in the LL
        }
    }
    free(hashTable->buckets);                           //free the memory for the buckets 
    free(hashTable);                                    //free the memory for the hash table
}

void *insertItem(HashTable *hashTable, unsigned int key, void *value)
{
    // TODO: Implement
    //1. First, we want to check if the key is present in the hash table.
        
    //2. If the key is present in the hash table, store new value and return old value

    //3. If not, create entry for new value and return NULL
    HashTableEntry *exists = findItem(hashTable, key);                      //create a local bucket using findItem to see if bucket with key exists in table
    if (exists != NULL) {                                                   //check if there is bucket in table with the key passed in
        void *prevValue = exists->value;                                    //set local variable prevValue to bucket's current value
        exists->value = value;                                              //set bucket's value to new value passed in
        return prevValue;                                                   //return old value
    }
    unsigned int bucketNum = hashTable->hash(key);                          //find which LL(chain) the key would go into
    HashTableEntry *thisBucket = hashTable->buckets[bucketNum];             //create bucket set to head entry for chain the key corresponds to
    if (thisBucket == NULL) {                                               //see if the chain was empty
        hashTable->buckets[bucketNum] = createHashTableEntry(key,value);    //create an entry in the chain if it was emtpy
        return NULL;
    }
    HashTableEntry *newEntry = createHashTableEntry(key, value);            //create an entry with the values passed in 
    newEntry->next = thisBucket;                                            //set next of new entry to the head of the chain
    hashTable->buckets[bucketNum] = newEntry;                               //set head of chain to the new entry 
    return NULL;
}

void *getItem(HashTable *hashTable, unsigned int key)
{
    // TODO: Implement
    //1. First, we want to check if the key is present in the hash table.

    //2. If the key exist, return the value
    
    //3. If not. just return NULL
    HashTableEntry *correctBucket = findItem(hashTable, key);   //create entry and set entry with findItem to see if entry with key exists
    if (correctBucket != NULL) {                                //see if entry with key already exists
        return correctBucket->value;                            //return entry's value if it exists in the table
    }
    return NULL;                                                //return NULL if entry does not exist in table
}

void *removeItem(HashTable *hashTable, unsigned int key)
{
    // TODO: Implement
    //1. Get the bucket number and the head entry
    
    //2. If the head holds the key, change the head to the next value, and return the old value
    
    //3. If not the head, earch for the key to be removed 
    
    //4. Uf the key is not present in the list, return NULL
    
    //5. Unlink node from the list and return old value
    unsigned int bucketNum = hashTable->hash(key);                          //find which LL(chain) the key would go into
    HashTableEntry *thisBucket = hashTable->buckets[bucketNum];             //create bucket set to head entry for chain the key corresponds to
    if (thisBucket == NULL) {                                               //if chain is empty return NULL
        return NULL;
    }
    if (thisBucket->key == key) {                                           //if chain is not emtpy, check if key is the one we are passed
        void *prevValue = thisBucket->value;                                //create local variable set to the value of entry in the chain for the key
        hashTable->buckets[bucketNum] = thisBucket->next;                   //set head of chain to the next entry 
        free(thisBucket);                                                   //free the memory for the previous entry 
        return prevValue;                                                   //return value for entry we just freed
    }
    while (thisBucket->next != NULL && (thisBucket->next)->key != key) {    //iterate through chain until we find key or reach end of the chain
        thisBucket = thisBucket->next;
    }
    if (thisBucket->next == NULL) {                                         //if we reach the end of the chain without finding the key, return NULL
        return NULL;
    }
    void *prevValue = (thisBucket->next)->value;                            //create local variable set to value of next entry
    HashTableEntry *delNode = thisBucket->next;                             //create local entry pointer set to node that is to be removed
    thisBucket->next = (thisBucket->next)->next;                            //set next of entry to the next of the next entry 
    free(delNode);                                                          //free the node that local entry pointer is pointing to
    return prevValue;                                                       //return the pointer to the value of entry that was removed 
}

void deleteItem(HashTable *hashTable, unsigned int key)
{
    // TODO: Implement
    //1. Remove the entry and free the returned data
    free(removeItem(hashTable,key));                                        //call removeItem and free the entry in hashtable passed in with key passed in
}
