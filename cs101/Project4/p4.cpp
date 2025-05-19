#include <iostream>
#include <string>

#include "p4.h"

using namespace std;

Person::Person()
{
    this->height = 0;
    this->weight = 0;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

Person::Person(string first, string last, int height, int weight)
{
    this->first = first;
    this->last = last;
    this->height = height;
    this->weight = weight;
    this->nextHeight = nullptr;
    this->nextWeight = nullptr;
}

void Person::Print(ostream &os) {       // print an individual person node onto the output stream
    os << first << " " << last << ": " << "height=" << height << ", weight=" << weight << endl;
}

PersonList::PersonList()
{
    this->size = 0;
    this->headHeightList = nullptr;
    this->headWeightList = nullptr;
}

int PersonList::getSize()
{
    return size;
    
}

void PersonList::printByHeight(ostream &os)     // print each person in order of ascending height
{
    Person* cur = headHeightList;
    while (cur != nullptr) {
        cur->Print(os);
        cur = cur->nextHeight;
    }
    os << endl;
}

void PersonList::printByWeight(ostream &os)     // same as printbyHeight with head and next ptr changed
{
    Person* cur = headWeightList;
    while (cur != nullptr) {
        cur->Print(os);
        cur = cur->nextWeight;
    }
    os << endl;
}

bool PersonList::exists(string first, string last)
{
    Person* cur = headHeightList;
    while (cur != nullptr) {
        if (cur->first == first && cur->last == last) return true;
        else cur = cur->nextHeight;
    }
    return false;
}

int PersonList::getHeight(string first, string last) {
    if (!this->exists(first, last)) return -1;                    // use other function to check whether person exists
    
    // if they do, search for person
    Person* cur = headHeightList;
    while (cur != nullptr) {
        if (cur->first == first && cur->last == last) return cur->height;
        cur = cur->nextHeight;
    }

    return -1;      // just in case. shouldnt be needed though

}

int PersonList::getWeight(string first, string last) {
    if (!this->exists(first, last)) return -1;                 // use other function to check whether person exists
    
    // if they do, search for person
    Person* cur = headWeightList;
    while (cur != nullptr) {
        if (cur->first == first && cur->last == last) return cur->weight;
        cur = cur->nextWeight;
    }

    return -1;      // just in case, shouldnt be needed.

}


// HELPER COMPARE FUNCTIONS to aid in inserting new persons in add function

bool whosHeavier(Person* firstGuy, Person* newGuy) {            // returns 0 if first guy is lighter, 1 if second guy. Uses weight as tie breaker. If both are same return 0 
    
    if (firstGuy->weight == newGuy->weight) {
        if (firstGuy->height == newGuy->height) return false;
        else return (firstGuy->height > newGuy->height);        // if first guy is taller returns true since height is sorted descendingly
    }

    else return (firstGuy->weight < newGuy->weight);            // returns true if second guy is heavier as weight is ascending
}

bool whosTaller(Person* firstGuy, Person* newGuy) {              //similar to function above

    if (firstGuy->height == newGuy->height) {
        if (firstGuy->weight == newGuy->weight) return false;
        else return (firstGuy->weight < newGuy->weight);        // operator swapped as weight is descending. Returns true if second guy weighs more
    }

    else return (firstGuy->height > newGuy->height);            //operator swapped as height is ascending. Returns true if second guy is shorter

}

// ------------------------------------------------------------------------

bool PersonList::add(string first, string last, int height, int weight) {
    if (exists(first, last)) return false;                                  // return false if person already exists

    Person* p = new Person(first, last, height, weight);                    // If doesn't exist, allocate new person and increment size by one
    size++;

    //              Insert by Height
    if (!headHeightList || whosTaller(p, headHeightList)) {                 // If list is empty or new node is taller than head, place first
        p->nextHeight = headHeightList;
        headHeightList = p;
    } else {
        Person* curr = headHeightList;
        while (curr->nextHeight && !whosTaller(p, curr->nextHeight)) {
            curr = curr->nextHeight;
        }
        p->nextHeight = curr->nextHeight;
        curr->nextHeight = p;
    }

    //              Insert by Weight
    if (!headWeightList || whosHeavier(p, headWeightList)) {                // If list is empty or new node is lighter than head, place first
        p->nextWeight = headWeightList;
        headWeightList = p;
    } else {
        Person* curr = headWeightList;
        while (curr->nextWeight && !whosHeavier(p, curr->nextWeight)) {
            curr = curr->nextWeight;
        }
        p->nextWeight = curr->nextWeight;
        curr->nextWeight = p;
    }

    return true;
}

bool PersonList::remove(string first, string last)
{
    if (!exists(first,last)) return false;

    // REMOVE FROM HEIGHT LIST
    Person *prev = nullptr, *cur = headHeightList;              // use two ptrs to iterate through current node and previous one

    while (cur) {                                               // while second pointer is not nullptr
        if (cur->first == first && cur->last == last) {
            if (prev) prev->nextHeight = cur->nextHeight;       // if not at beginning of list, set nextHeight of prev node to cur->nextHeigh
            else headHeightList = cur->nextHeight;              // If at beginning of list, just set headHeightList to next node
            break;
        }
        prev = cur;
        cur = cur->nextHeight;
    }

    // REMOVE FROM WEIGHT LIST  -  Same as above but with weight ptrs
    prev = nullptr, cur = headWeightList;              // use two ptrs to iterate through current node and previous one

    while (cur) {                                               // while second pointer is not nullptr
        if (cur->first == first && cur->last == last) {
            if (prev) prev->nextWeight = cur->nextWeight;       // if not at beginning of list, set nextHeight of prev node to cur->nextHeigh
            else headWeightList = cur->nextWeight;              // If at beginning of list, just set headHeightList to next node
            break;
        }
        prev = cur;
        cur = cur->nextWeight;
    }

    delete cur;                 // Cur will end on whichever node is to be deleted/matches the first and last name
    size--;                     // iterate size accordingly
    return true;
}

bool PersonList::updateName(string first, string last, string newFirst, string newLast)
{
    if (!exists(first, last)) return false;                 // if non existent return false immediately

    // if person does exist:
    Person* cur = headWeightList;
    while (cur != nullptr) {
        if (cur->first == first && cur->last == last) {     // once found update name
            cur->first = newFirst;
            cur->last = newLast;
            return true;
        }
        cur = cur->nextWeight;
    }

    return false;
}

bool PersonList::updateHeight(string first, string last, int height)
{
    if (!exists(first,last)) return false;      // Make sure the person actually exists

    int weight = getWeight(first, last);        // Get the weight from the old node

    remove(first, last);                        // Remove the old node
    add(first, last, height, weight);           // Create new node with the same name and weight, but updated height

    return true;
}

bool PersonList::updateWeight(string first, string last, int weight)    //Again, pretty much the same as the above function, swap weight and height
{
    if (!exists(first,last)) return false;      // Make sure the person actually exists

    int height = getHeight(first, last);        // Get the weight from the old node

    remove(first, last);                        // Remove the old node
    add(first, last, height, weight);           // Create new node with the same name and weight, but updated height
    
    return true;
}

// Constructor, Destructor and Equal Assignment Operator (RULE OF 3)

PersonList::~PersonList()
{
    Person *ptr = headHeightList;               // Can go by either height or weight, it doesnt matter. But should only go through the list once either way.
    while (ptr) {
        Person *temp = ptr->nextHeight;         // Set temp to next node, then delete current one, and set the next node based to temp
        delete ptr;
        ptr = temp;
    }

    headHeightList = nullptr;
    headWeightList = nullptr;
    size = 0;
}

PersonList::PersonList(const PersonList &src)
{   
    headHeightList = nullptr;                   // Initialize as empty list so code doesnt fail if src is empty
    headWeightList = nullptr;
    size = 0;

    Person *curOld = src.headHeightList;
    while (curOld) {                            // Go through old list and add each node to new list one by one. Should be in both correct weight nad height order
        add(curOld->first,curOld->last, curOld->height, curOld->weight);
        curOld = curOld->nextHeight;
    }
}

const PersonList &PersonList::operator=(const PersonList &src)
{
    if (this == &src) return *this;             // Check for self assignment

    // Clear Old List - Reusing destructor logic
    Person *ptr = headHeightList;               // Can go by either height or weight, it doesnt matter. But should only go through the list once either way.
    while (ptr) {
        Person *temp = ptr->nextHeight;         // Set temp to next node, then delete current one, and set the next node based to temp
        delete ptr;
        ptr = temp;
    }

    headHeightList = nullptr;
    headWeightList = nullptr;
    size = 0;


    // Copy Over New list - Reusing copy constructor logic
    Person *curOld = src.headHeightList;
    while (curOld) {                            // Go through old list and add each node to new list one by one. Should be in both correct weight nad height order
        add(curOld->first,curOld->last, curOld->height, curOld->weight);
        curOld = curOld->nextHeight;
    }

    return *this;
}
