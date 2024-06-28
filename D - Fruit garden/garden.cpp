#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

GARDEN_CLASS::GARDEN_CLASS() {
    head = new TREE_CLASS();
    last = NULL;
    totalTrees = 0;
    totalBranches = 0;
    totalFruits = 0;
    totalWeights = 0;
    gap = 0;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    while (head != NULL) {
        TREE_CLASS* nextTree = head->getNext();
        delete head;
        head = nextTree;
    }
}

unsigned int GARDEN_CLASS::getTreesTotal(void) {
    return totalTrees;
}

unsigned int GARDEN_CLASS::getBranchesTotal(void) {
    return totalBranches;
}

unsigned int GARDEN_CLASS::getFruitsTotal(void) {
    return totalFruits;
}

unsigned int GARDEN_CLASS::getWeightsTotal(void) {
    return totalWeights;
}

void GARDEN_CLASS::plantTree(void) {
    if (head->getNext() == NULL) {
        head->setNext(new TREE_CLASS(this, 0));
        last = head->getNext();
    } else {
        if (gap > 0) {
            TREE_CLASS* currentTree = this->head->getNext();
            if (currentTree->getNext() == NULL) {
                if (currentTree->getNumber() > 0) {
                    currentTree->setPrev(new TREE_CLASS(this, 0));
                    currentTree->getPrev()->setNext(currentTree);
                    head->setNext(currentTree->getPrev());
                    gap--;
                } else if (currentTree->getNumber() == 0) {
                    currentTree->setNext(new TREE_CLASS(this, 1));
                    currentTree->getNext()->setPrev(currentTree);
                }
            }
            else if (currentTree->getNumber() > 0) {
                currentTree->setPrev(new TREE_CLASS(this, 0));
                currentTree->getPrev()->setNext(currentTree);
                head->setNext(currentTree->getPrev());
                gap--;
            } else {
                while (currentTree->getNext() != NULL) {
                    if (currentTree->getNext()->getNumber() - currentTree->getNumber() > 1) {
                        TREE_CLASS* newTree = new TREE_CLASS(this, currentTree->getNumber() + 1);
                        newTree->setNext(currentTree->getNext());
                        newTree->setPrev(currentTree);
                        currentTree->getNext()->setPrev(newTree);
                        currentTree->setNext(newTree);
                        gap--;
                        break;
                    }
                    currentTree = currentTree->getNext();
                }
            }
            currentTree = NULL;
        } else {
            last->setNext(new TREE_CLASS(this, last->getNumber() + 1));
            last->getNext()->setPrev(last);
            last = last->getNext();
        }
    }
}

void GARDEN_CLASS::extractTree(unsigned int n) {
    if (totalTrees < 1) return;
    if (n <= last->getNumber()) {
        if (totalTrees == 1) {
            delete head->getNext();
            head->setNext(NULL);
            return;
        } else if (last->getNumber() == n) {
            last = last->getPrev();
            delete last->getNext();
            last->setNext(NULL);
            return;
        } else if (head->getNext()->getNumber() == n) {
            TREE_CLASS* toDelete = head->getNext();
            head->setNext(toDelete->getNext());
            delete toDelete;
            if (head->getNext()) {
                head->getNext()->setPrev(NULL);
            }
            gap++;
            return;
        } else {
            TREE_CLASS* current = head->getNext();
            while (current != NULL) {
                if (current->getNumber() == n) {
                    current->getPrev()->setNext(current->getNext());
                    if (current->getNext()) {
                        current->getNext()->setPrev(current->getPrev());
                    }
                    delete current;
                    gap++;
                    return;
                }
                current = current->getNext();
            }
        }
    }
}

void GARDEN_CLASS::growthGarden(void) {
    TREE_CLASS* current = head->getNext();
    while (current != NULL) {
        current->growthTree();
        current = current->getNext();
    }
}

void GARDEN_CLASS::fadeGarden(void) {
    TREE_CLASS* current = head->getNext();
    while (current != NULL) {
        current->fadeTree();
        current = current->getNext();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int n) {
    TREE_CLASS* current = head->getNext();
    while (current != NULL) {
        current->harvestTree(n);
        current = current->getNext();
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int n) {
    TREE_CLASS *current = head->getNext();
    while (current != NULL && current->getNumber() != n) {
        current = current->getNext();
    }
    return current;
}

void GARDEN_CLASS::cloneTree(unsigned int n) {
    if (head == NULL) return;
    
    TREE_CLASS* originalTree = getTreePointer(n);
    if (originalTree == NULL) return;
    
    TREE_CLASS* current = head->getNext();
    TREE_CLASS* newTree = NULL;
    
    newTree = new TREE_CLASS(*originalTree);
    newTree->setGarden(this);
    
    if (current->getNext() == NULL) {
        if (current->getNumber() > 0) {
            head->setNext(newTree);
            newTree->setNext(current);
            newTree->setPrev(NULL);
            newTree->setTreeId(0);
            current->setPrev(newTree);
            gap--;
        } else {
            current->setNext(newTree);
            newTree->setPrev(current);
            newTree->setTreeId(current->getNumber() + 1);
        }
    }
    else {
        while (current->getNext() != NULL && (current->getNext()->getNumber() - current->getNumber() == 1))
            current = current->getNext();
        
        newTree->setTreeId(current->getNumber() + 1);
        newTree->setNext(current->getNext());
        newTree->setPrev(current);
        if (current->getNext() != NULL) current->getNext()->setPrev(newTree);
        else last = newTree;
        current->setNext(newTree);
        gap--;
    }
    
    addTrees(1);
    addBranches(originalTree->getBranchesTotal());
    addFruits(originalTree->getFruitsTotal());
    addWeight(originalTree->getWeightsTotal());
}

void GARDEN_CLASS::addTrees(unsigned int n) {
    totalTrees += n;
}

void GARDEN_CLASS::addBranches(unsigned int n) {
    totalBranches += n;
}

void GARDEN_CLASS::addFruits(unsigned int n) {
    totalFruits += n;
}

void GARDEN_CLASS::addWeight(unsigned int n) {
    totalWeights += n;
}

void GARDEN_CLASS::reduceTrees(unsigned int n) {
    if (totalTrees >= n) totalTrees -= n;
}

void GARDEN_CLASS::reduceBranches(unsigned int n) {
    if (totalBranches >= n) totalBranches -= n;
}

void GARDEN_CLASS::reduceFruits(unsigned int n) {
    if (totalFruits >= n) totalFruits -= n;
}

void GARDEN_CLASS::reduceWeight(unsigned int n) {
    if (totalWeights >= n) totalWeights -= n;
}
