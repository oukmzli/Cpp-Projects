#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

BRANCH_CLASS::BRANCH_CLASS() {
    branchLength = 0;
    branchHeight = 0;
    totalFruits = 0;
    totalWeights = 0;
    tree = NULL;
    next = NULL;
    prev = NULL;
    head = NULL;
    last = NULL;
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& other) {
    if (other.head != NULL) {
        head = new FRUIT_CLASS(this);
        if (other.head->getNext() == NULL)
            last = NULL;
        else {
            FRUIT_CLASS *otherFruit = other.head->getNext();
            head->setNext(new FRUIT_CLASS(this));
            head->getNext()->setPrev(NULL);
            
            FRUIT_CLASS *currentFruit = head->getNext();
            while (otherFruit != NULL) {
                currentFruit->addWeight(otherFruit->getWeight());
                currentFruit->setLenght(otherFruit->getLength());
                if (otherFruit->getNext() == NULL)
                    currentFruit->setNext(NULL);
                else {
                    currentFruit->setNext(new FRUIT_CLASS(this));
                    currentFruit->getNext()->setPrev(currentFruit);
                    currentFruit = currentFruit->getNext();
                }
                otherFruit = otherFruit->getNext();
            }
            last = currentFruit;
        }
    } else {
        head = NULL;
        last = NULL;
    }
    totalFruits = other.totalFruits;
    totalWeights = other.totalWeights;
    branchHeight = other.branchHeight;
    branchLength = other.branchLength;
    tree = NULL;
    prev = NULL;
    next = NULL;
}

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* tree, unsigned int height) {
    branchLength = 0;
    branchHeight = height;
    totalFruits = 0;
    totalWeights = 0;
    this->tree = tree;
    next = NULL;
    prev = NULL;
    head = new FRUIT_CLASS();
    last = NULL;
    
    if (this->tree != NULL) {
        this->tree->addBranches(1);
        GARDEN_CLASS* garden = this->tree->getGardenPointer();
        if (garden != NULL) {
            garden->addBranches(1);
        }
    }
}

BRANCH_CLASS::~BRANCH_CLASS() {
    prev = NULL;
    next = NULL;
    
    if (tree != NULL && tree->getBranchesTotal() > 0) {
        tree->reduceBranches(1);
        GARDEN_CLASS* garden = tree->getGardenPointer();
        if (garden != NULL) {
            garden->reduceBranches(1);
        }
    }
    
    FRUIT_CLASS* current;
    while (head != NULL) {
        current = head;
        head = head->getNext();
        delete current;
    }
    last = NULL;
    tree = NULL;
}


unsigned int BRANCH_CLASS::getFruitsTotal(void) {
    return totalFruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal(void) {
    return totalWeights;
}

unsigned int BRANCH_CLASS::getHeight(void) {
    return branchHeight;
}

unsigned int BRANCH_CLASS::getLength(void) {
    return branchLength;
}

void BRANCH_CLASS::growthBranch(void) {
    branchLength++;
    if (head == NULL) head = new FRUIT_CLASS();
    
    FRUIT_CLASS *current = head->getNext();
    while (current != NULL) {
        current->growthFruit();
        current = current->getNext();
    }
    if (branchLength % 2 == 0) {
        if (head->getNext() == NULL) {
            head->setNext(new FRUIT_CLASS(this));
            last = head->getNext();
        } else{
            last->setNext(new FRUIT_CLASS(this));
            last->getNext()->setPrev(last);
            last = last->getNext();
        }
    }
    current = NULL;
}

void BRANCH_CLASS::fadeBranch(void) {
    if (branchLength > 0) branchLength--;
    if (head != NULL) {
        FRUIT_CLASS *current = head->getNext();
        FRUIT_CLASS *toDelete;
        if (current != NULL) {
            while (current != NULL) {
                toDelete = current;
                current = current->getNext();
                if (toDelete->getLength() > branchLength) {
                    if (toDelete->getPrev() != NULL && toDelete->getNext() != NULL) {
                        toDelete->getNext()->setPrev(toDelete->getPrev());
                        toDelete->getPrev()->setNext(toDelete->getNext());
                    }
                    else if (toDelete->getPrev() != NULL && toDelete->getNext() == NULL) {
                        last = last->getPrev();
                        last->setNext(NULL);
                    }
                    else if (toDelete->getPrev() == NULL && toDelete->getNext() == NULL)
                        head->setNext(NULL);
                    else if (toDelete->getPrev() == NULL && toDelete->getNext() != NULL) {
                        head->setNext(head->getNext()->getNext());
                        head->setPrev(NULL);
                    }
                    delete toDelete;
                }
                else toDelete->fadeFruit();
            }
        }
        current = NULL;
        toDelete = NULL;
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int n) {
    FRUIT_CLASS* current = head->getNext();
    while (current != NULL) {
        if (current->getWeight() >= n)
            current->pluckFruit();
        current = current->getNext();
    }
    current = NULL;
}

void BRANCH_CLASS::cutBranch(unsigned int n) {
    if (n < branchLength) {
        branchLength = n;
        if (head != NULL) {
            FRUIT_CLASS *current = head->getNext();
            FRUIT_CLASS *toDelete;
            while (current != NULL) {
                toDelete = current;
                current = current->getNext();
                if (toDelete->getLength() > n) {
                    if (toDelete->getPrev() != NULL && toDelete->getNext() != NULL) {
                        toDelete->getNext()->setPrev(toDelete->getPrev());
                        toDelete->getPrev()->setNext(toDelete->getNext());
                    }
                    else if (toDelete->getPrev() != NULL && toDelete->getNext() == NULL) {
                        last = last->getPrev();
                        last->setNext(NULL);
                    }
                    else if (toDelete->getPrev() == NULL && toDelete->getNext() == NULL)
                        head->setNext(NULL);
                    else if (toDelete->getPrev() == NULL && toDelete->getNext() != NULL) {
                        head->setNext(head->getNext()->getNext());
                        head->getNext()->setPrev(NULL);
                    }
                    delete toDelete;
                }
            }
            current = NULL;
        }
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int arg) {
    FRUIT_CLASS* current = head->getNext();
    while (current != NULL && current->getLength() != arg) {
        current = current->getNext();
    }
    return current;
}

TREE_CLASS* BRANCH_CLASS::getTreePointer(void) {
    return tree;
}


void BRANCH_CLASS::setNext(BRANCH_CLASS* ptr) {
    next = ptr;
}

void BRANCH_CLASS::setPrev(BRANCH_CLASS* ptr) {
    prev = ptr;
}

BRANCH_CLASS * BRANCH_CLASS::getNext(void) {
    return next;
}

BRANCH_CLASS* BRANCH_CLASS::getPrev(void) {
    return prev;
}

void BRANCH_CLASS::setTree(TREE_CLASS* tree) {
    this->tree = tree;
}

void BRANCH_CLASS::addLength(unsigned int n) {
    branchLength += n;
}

void BRANCH_CLASS::addHeight(unsigned int n) {
    branchHeight += n;
}

void BRANCH_CLASS::addFruits(unsigned int n) {
    totalFruits += n;
}

void BRANCH_CLASS::addWeight(unsigned int n) {
    totalWeights += n;
}

void BRANCH_CLASS::reduceLength(unsigned int n) {
    if (branchLength >= n)
        branchLength -= n;
}

void BRANCH_CLASS::reduceHeight(unsigned int n) {
    if (branchHeight >= n)
        branchHeight -= n;
}

void BRANCH_CLASS::reduceFruits(unsigned int n) {
    if (totalFruits >= n)
        totalFruits -= n;
}

void BRANCH_CLASS::reduceWeight(unsigned int n) {
    if (totalWeights >= n)
        totalWeights -= n;
}

void BRANCH_CLASS::setHeight(unsigned int n) {
    branchHeight = n;
}
