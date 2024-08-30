/* Dictionary => general-purpose data structure for storing group of objs
they have a set of keys and each key has single associated value
when presented with key, dictionary will return associated value
they are also called "map" in different programming languages */

results = { 'Charlie' : 8,
           'Anna' : 7,
           'Michael' : 5, 
           'Luna' : 9,
           'Tom' : 6 }

/* dictionary name => results 
Charlie, Anna, Michael, Luna, Tom are keys & 8, 7, 5, 9, 6 are the associated values 
keys can only have 1 unique value

use dictionary keys (names) to return values
for instance, results['Anna'] = 7 
              results['Tom'] = 6 

keys in a dictionary must be simple types (integers/strings for example) while values can be of any type
dictionaries are often implemented as hash tables
keys in a dictionary must be unique or else duplicate keys will typically overwrite existing values for the preceding keys

Dictionary is an abstract data structure that supports the following operations: */
search(K key) // returns the value associated with the given key
insert(K key, V value)
delete(K key)

/* Dictionaries have numerous applications: 
Contact Book - key: name of person | value 
Telephone Number Table - key: identifier | value: address in memory
Property Value Collection - key: property name | value: associated value */