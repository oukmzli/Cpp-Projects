#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

FRUIT_CLASS::FRUIT_CLASS() {
    weight = 0;
    growthLenght = 0;
    branch = NULL;
    next = NULL;
    prev = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& other) {
    weight = other.weight;
    growthLenght = other.growthLenght;
    branch = other.branch;
    next = NULL;
    prev = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* otherBranch) {
    weight = 0;
    growthLenght = otherBranch->getLength();
    branch = otherBranch;
    next = NULL;
    prev = NULL;
    
    if (otherBranch != NULL) {
        otherBranch->addFruits(1);
        TREE_CLASS* tree = otherBranch->getTreePointer();
        if (tree != NULL) {
            tree->addFruits(1);
            GARDEN_CLASS* garden = tree->getGardenPointer();
            if (garden != NULL) {
                garden->addFruits(1);
            }
        }
    }
}

FRUIT_CLASS::~FRUIT_CLASS() {
    next = NULL;
    prev = NULL;
    pluckFruit();
    if (branch != NULL && branch->getFruitsTotal() > 0) {
        branch->reduceFruits(1);
        TREE_CLASS* tree = branch->getTreePointer();
        if (tree != NULL) {
            tree->reduceFruits(1);
            GARDEN_CLASS* garden = tree->getGardenPointer();
            if (garden != NULL) {
                garden->reduceFruits(1);
            }
        }
    }
    branch = NULL;
}

unsigned int FRUIT_CLASS::getLength(void) {
    return growthLenght;
}

unsigned int FRUIT_CLASS::getWeight(void) {
    return weight;
}

void FRUIT_CLASS::growthFruit(void) {
    weight++;
    if (branch != NULL) {
        branch->addWeight(1);
        TREE_CLASS* tree = branch->getTreePointer();
        if (tree != NULL) {
            tree->addWeight(1);
            GARDEN_CLASS* garden = tree->getGardenPointer();
            if (garden != NULL) {
                garden->addWeight(1);
            }
        }
    }
}

void FRUIT_CLASS::fadeFruit(void) {
    if (weight > 0) weight--;
    if (branch != NULL) {
        branch->reduceWeight(1);
        TREE_CLASS* tree = branch->getTreePointer();
        if (tree != NULL) {
            tree->reduceWeight(1);
            GARDEN_CLASS* garden = tree->getGardenPointer();
            if (garden != NULL) {
                garden->reduceWeight(1);
            }
        }
    }
}

void FRUIT_CLASS::pluckFruit(void) {
    if (branch != NULL) {
        branch->reduceWeight(weight);
        TREE_CLASS* tree = branch->getTreePointer();
        if (tree != NULL) {
            tree->reduceWeight(weight);
            GARDEN_CLASS* garden = tree->getGardenPointer();
            if (garden != NULL) {
                garden->reduceWeight(weight);
            }
        }
    }
    weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer(void) {
    return branch;
}

void FRUIT_CLASS::setLenght(unsigned int n) {
    growthLenght = n;
}

void FRUIT_CLASS::addWeight(unsigned int n) {
    weight += n;
}

FRUIT_CLASS* FRUIT_CLASS::getNext(void) {
    return next;
}

FRUIT_CLASS* FRUIT_CLASS::getPrev(void) {
    return prev;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS* ptr) {
    next = ptr;
}

void FRUIT_CLASS::setPrev(FRUIT_CLASS* ptr) {
    prev = ptr;
}

void FRUIT_CLASS::setBranch(BRANCH_CLASS* branch) {
    this->branch = branch;
}
