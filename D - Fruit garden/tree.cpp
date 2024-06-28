#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

TREE_CLASS::TREE_CLASS() {
    treeId = 0;
    treeHeight = 0;
    totalBranches = 0;
    totalFruits = 0;
    totalWeight = 0;
    garden = NULL;
    next = NULL;
    prev = NULL;
    head = NULL;
    last = NULL;
}

TREE_CLASS::TREE_CLASS(GARDEN_CLASS* garden, unsigned int id) {
    treeId = id;
    treeHeight = 0;
    totalBranches = 0;
    totalFruits = 0;
    totalWeight = 0;
    this->garden = garden;
    next = NULL;
    prev = NULL;
    head = new BRANCH_CLASS();
    last = NULL;
    if (this->garden != NULL) this->garden->addTrees(1);
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS& other) {
    treeId = other.treeId;
    treeHeight = other.treeHeight;
    totalBranches = other.totalBranches;
    totalFruits = other.totalFruits;
    totalWeight = other.totalWeight;
    garden = other.garden;
    next = NULL;
    prev = NULL;
    head = NULL;
    last = NULL;
    
    BRANCH_CLASS* current = other.head;
    while (current != NULL) {
        BRANCH_CLASS* newBranch = new BRANCH_CLASS(*current);
        newBranch->setTree(this);
        
        if (last == NULL) {
            head = newBranch;
            last = newBranch;
            newBranch->setNext(NULL);
            newBranch->setPrev(NULL);
        } else {
            last->setNext(newBranch);
            newBranch->setPrev(last);
            newBranch->setNext(NULL);
            last = newBranch;
        }
        current = current->getNext();
    }
}

TREE_CLASS::~TREE_CLASS() {
    next = NULL;
    prev = NULL;
    last = NULL;
    if (garden != NULL) garden->reduceTrees(1);
    while (head != NULL) {
        BRANCH_CLASS* nextBranch = head->getNext();
        delete head;
        head = nextBranch;
    }
}

unsigned int TREE_CLASS::getBranchesTotal() {
    return totalBranches;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return totalFruits;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return totalWeight;
}

unsigned int TREE_CLASS::getNumber() {
    return treeId;
}

unsigned int TREE_CLASS::getHeight() {
    return treeHeight;
}

void TREE_CLASS::growthTree() {
    treeHeight++;
    if (head == NULL) head = new BRANCH_CLASS();
    BRANCH_CLASS* current = head->getNext();
    while (current != NULL) {
        current->growthBranch();
        current = current->getNext();
    }
    if (treeHeight % 3 == 0) {
        if (head->getNext() == NULL) {
            head->setNext(new BRANCH_CLASS(this, treeHeight));
            last = head->getNext();
        } else {
            last->setNext(new BRANCH_CLASS(this, treeHeight));
            last->getNext()->setPrev(last);
            last = last->getNext();
        }
    }
}

void TREE_CLASS::fadeTree() {
    if (treeHeight > 0) treeHeight--;
    
    BRANCH_CLASS* current = head;
    while (current != NULL) {
        current->fadeBranch();
        current = current->getNext();
    }
    
    current = head;
    BRANCH_CLASS* toDelete;
    while (current != NULL) {
        toDelete = current;
        current = current->getNext();
        if (toDelete->getHeight() > treeHeight) {
            if (toDelete->getPrev() != NULL && toDelete->getNext() != NULL) {
                toDelete->getPrev()->setNext(toDelete->getNext());
                toDelete->getNext()->setPrev(toDelete->getPrev());
            }
            else if (toDelete->getPrev() != NULL && toDelete->getNext() == NULL) {
                last = toDelete->getPrev();
                last->setNext(NULL);
            }
            else if (toDelete->getPrev() == NULL && toDelete->getNext() == NULL) {
                head = NULL;
                last = NULL;
            }
            else if (toDelete->getPrev() == NULL && toDelete->getNext() != NULL) {
                head = toDelete->getNext();
                head->setPrev(NULL);
            }
            delete toDelete;
        }
    }
}

void TREE_CLASS::harvestTree(unsigned int n) {
    BRANCH_CLASS* current = head->getNext();
    while (current != NULL) {
        current->harvestBranch(n);
        current = current->getNext();
    }
}

void TREE_CLASS::cutTree(unsigned int height) {
    if (height < treeHeight) {
        treeHeight = height;
        BRANCH_CLASS* currentBranch = head->getNext();
        
        while (currentBranch != NULL) {
            BRANCH_CLASS* branchToDelete;
            if (currentBranch->getHeight() > height) {
                branchToDelete = currentBranch;
                currentBranch = currentBranch->getNext();
                
                if (branchToDelete->getPrev() != NULL) {
                    branchToDelete->getPrev()->setNext(branchToDelete->getNext());
                }
                
                if (branchToDelete->getNext() != NULL) {
                    branchToDelete->getNext()->setPrev(branchToDelete->getPrev());
                }
                
                if (branchToDelete == head->getNext()) {
                    head->setNext(branchToDelete->getNext());
                }
                
                if (branchToDelete == last) {
                    last = branchToDelete->getPrev();
                    if (last != NULL) {
                        last->setNext(NULL);
                    }
                }
                
                delete branchToDelete;
            } else {
                currentBranch = currentBranch->getNext();
            }
        }
    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* branchToClone) {
    if (branchToClone == NULL || head == NULL || head->getNext() == NULL) return;
    
    BRANCH_CLASS* targetBranch = head->getNext();
    while (targetBranch != NULL) {
        if (targetBranch->getLength() == 0) {
            BRANCH_CLASS* newBranch = new BRANCH_CLASS(*branchToClone);

            newBranch->setPrev(targetBranch->getPrev());
            newBranch->setNext(targetBranch->getNext());
            newBranch->setTree(this);
            newBranch->setHeight(targetBranch->getHeight());

            if (targetBranch->getPrev() != NULL) {
                targetBranch->getPrev()->setNext(newBranch);
            }
            if (targetBranch->getNext() != NULL) {
                targetBranch->getNext()->setPrev(newBranch);
            }

            if (head->getNext() == targetBranch) {
                head->setNext(newBranch);
            }
            if (last == targetBranch) {
                last = newBranch;
            }

            delete targetBranch;

            addBranches(1);
            addFruits(newBranch->getFruitsTotal());
            addWeight(newBranch->getWeightsTotal());

            if (getGardenPointer() != NULL) {
                getGardenPointer()->addBranches(1);
                getGardenPointer()->addFruits(newBranch->getFruitsTotal());
                getGardenPointer()->addWeight(newBranch->getWeightsTotal());
            }
            break;
        }
        targetBranch = targetBranch->getNext();
    }
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return garden;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int branchId) {
    BRANCH_CLASS* current = head->getNext();
    while (current != NULL && current->getHeight() != branchId) {
        current = current->getNext();
    }
    return current;
}

void TREE_CLASS::addHeight(unsigned int n) {
    treeHeight += n;
}

void TREE_CLASS::addBranches(unsigned int n) {
    totalBranches += n;
}

void TREE_CLASS::addFruits(unsigned int n) {
    totalFruits += n;
}

void TREE_CLASS::addWeight(unsigned int n) {
    totalWeight += n;
}

void TREE_CLASS::reduceHeight(unsigned int n) {
    if (treeHeight >= n) treeHeight -= n;
}

void TREE_CLASS::reduceBranches(unsigned int n) {
    if (totalBranches >= n) totalBranches -= n;
}

void TREE_CLASS::reduceFruits(unsigned int n) {
    if (totalFruits >= n) totalFruits -= n;
}

void TREE_CLASS::reduceWeight(unsigned int n) {
    if (totalWeight >= n) totalWeight -= n;
}

TREE_CLASS* TREE_CLASS::getNext() {
    return next;
}

TREE_CLASS* TREE_CLASS::getPrev() {
    return prev;
}

void TREE_CLASS::setNext(TREE_CLASS* ptr) {
    next = ptr;
}

void TREE_CLASS::setPrev(TREE_CLASS* ptr) {
    prev = ptr;
}

void TREE_CLASS::setGarden(GARDEN_CLASS* garden) {
    this->garden = garden;
}

void TREE_CLASS::setTreeId(unsigned int n) {
    treeId = n;
}
