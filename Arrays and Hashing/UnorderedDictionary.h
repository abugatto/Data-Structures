#include <iostream>
#include <string>

using namespace std;

//Note: keytype must be int, float, char, or string
template<class KeyType, class ValueType>
class UnorderedDictionary {
    public:
        UnorderedDictionary() {

        }

        ~UnorderedDictionary() {

        }

        bool insert(const KeyType& key, ValueType& value) {

        }

        bool retreive(const KeyType& key, ValueType& value) {

        }

        bool remove(const KeyType& key, const ValueType& value) {

        }

    private:
        int hash(const KeyType& key) {
            if(std::is_same<KeyType, int>::value) {

            } else if(std::is_same<KeyType, float>::value) {

            } else if(std::is_same<KeyType, char>::value) {

            } else if(std::is_same<KeyType, string>::value) {

            } else  {
                return -1;
            }
        }
};