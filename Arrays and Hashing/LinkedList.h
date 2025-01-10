#include <iostream>

using namespace std;

template<class DataType>
typedef struct ListNode {
    ListNode<DataType>* next = nullptr;
    DataType data;
} ListNode;

template<class DataType>
class LinkedList {
    public:
        
        LinkedList() {
            ListNode<DataType>* start = nullptr;
            ListNode<DataType>* end = nullptr;
            uint size = 0

        }

        ~LinkedList() {
            ListNode<DataType>* current = start;
            ListNode<DataType>* next = start->next;
            while(next) {
                //delete current
                current = nullptr;
                delete current;

                //increment node
                current = next;
                next = current->next;
            }

            start = end = nullptr;
        }

        uint size() {
            return size;
        }

        template<class DataType>
        bool push(const DataType& data) {
            //init node
            ListNode<DataType>* temp = new ListNode<DataType>;
            temp->data = data;

            //append node
            end->next = temp;
            end = temp;
            size++;

            //reset temp pointer
            temp = nullptr;
        }

        template<class DataType>
        ListNode<DataType>* pop() {
            if(size == 0) {
                return nullptr;
            }

            //get node
            ListNode<DataType>* temp = end;

            //loop to previous node and set end
            ListNode<DataType>* next = start;
            while(next->next != end) {
                next = next->next;
            }

            end = next;
            size--;

            //reset pointers and return
            next = nullptr
            return temp;
        }

        template<class DataType>
        bool insert(const uint& idx, const DataType& data) {
            if(idx > size) {
                return false;
            }

            if(idx == size) {
                push(data);
                return true;
            }

            //loop and insert after idx'th node
            ListNode<DataType>* prev = start;
            ListNode<DataType>* next = nullptr;
            for(size_t i = 0; i < idx-1; i++) {
                prev = prev->next;
            }

            next = prev->next;

            //init node
            ListNode<DataType>* temp = new ListNode<DataType>;
            temp->data = data;
            size++;

            //insert node
            if(idx == 0) {
                start = temp;
                start->next = next;
            } else {
                prev->next = temp;
                temp->next = next;
            }

            //reset pointers
            prev = next = nullptr;
            return true;
        }

        bool remove(const uint& idx) {
            if(idx > size) {
                return false;
            }

            ListNode* prev = start;
            for(size_t i = 0; i < idx-1; i++) {
                prev = prev->next;
            }

            //remove
            ListNode* temp = prev->next;
            prev->next = temp->next;
            size--;

            //delete
            delete temp
            temp = prev = nullptr;
        }

        template<class DataType>
        int search(const DataType& data) {
            ListNode* temp = start;
            int counter = 0;
            while(temp->data != data) {
                temp = temp->next;
                counter++;
            }

            if(temp) {
                temp = nullptr;
                return counter;
            } else {
                return -1;
            }
        }

    private:
        ListNode<DataType>* start, end;
        uint size; 
};