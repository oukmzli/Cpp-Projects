#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

#include <iostream>

using namespace std;

void GARDEN_CLASS::display() {
    TREE_CLASS* tree;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getTreesTotal();
    
    printf("GARDEN:\n");
    printf("    Number of Trees: %u\n", quantity);
    printf("    Number of Branches: %u\n", (*this).getBranchesTotal());
    printf("    Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("    Total Weight: %u\n", (*this).getWeightsTotal());
    printf("    All Trees:\n");
    
    while (i < quantity) {
        tree = (*this).getTreePointer(j);
        if (tree != NULL) {
            (*tree).display();
            i += 1;
        }
        j += 1;
    }
    printf("    Successful Display all of %u Trees\n", quantity);
}

void TREE_CLASS::display() {
    BRANCH_CLASS* branch;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getBranchesTotal();
    
    printf("    Tree number %u:\n", (*this).getNumber());
    printf("        Height of a Tree: %u\n", (*this).getHeight());
    printf("        Number of Branches: %u\n", quantity);
    printf("        Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("        Total Weight: %u\n", (*this).getWeightsTotal());
    printf("        All Branches:\n");
    
    while (i < quantity) {
        branch = (*this).getBranchPointer(3 * j);
        if (branch != NULL) {
            (*branch).display();
            i += 1;
        }
        j += 1;
    }
    printf("        Successful Display all of %u Branches\n", quantity);
}

void BRANCH_CLASS::display() {
    FRUIT_CLASS* fruit;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getFruitsTotal();
    
    printf("        Branch at the height of %u\n", (*this).getHeight());
    printf("            Length of a Branch: %u\n", (*this).getLength());
    printf("            Number of Fruits: %u\n", quantity);
    printf("            Total Weight: %u\n", (*this).getWeightsTotal());
    printf("            All Fruits:\n");
    
    while (i < quantity) {
        fruit = (*this).getFruitPointer(j << 1);
        if (fruit != NULL) {
            (*fruit).display();
            i += 1;
        }
        j += 1;
    }
    printf("            Successful Display all of %u Fruits\n", quantity);
}

void FRUIT_CLASS::display() {
    printf("            Fruit at the length of %u\n", (*this).getLength());
    printf("                Weight: %u\n", (*this).getWeight());
}

int main() {
    TREE_CLASS* tree = new TREE_CLASS();
    tree->growthTree();
    tree->growthTree();
    tree->growthTree();
    tree->display();
    tree->cloneBranch(new BRANCH_CLASS(NULL, 3));
    tree->display();
    tree->cloneBranch(new BRANCH_CLASS(NULL, 9));
    tree->cloneBranch(new BRANCH_CLASS(NULL, 6));

    tree->display();

    BRANCH_CLASS* branchToClone = new BRANCH_CLASS(NULL, 21);
    tree->cloneBranch(branchToClone);

    tree->display();

    delete tree;
    return 0;
}

/*
int main() {
    
    GARDEN_CLASS*  garden = new GARDEN_CLASS();
    garden->plantTree();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->extractTree(2);
    garden->display();
    garden->plantTree();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->plantTree();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->extractTree(3);
    garden->display();
    garden->extractTree(3);
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->fadeGarden();
    garden->display();
    garden->fadeGarden();
    garden->display();
    garden->fadeGarden();
    garden->display();
    garden->fadeGarden();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->growthGarden();
    garden->display();
    garden->harvestGarden(3);
    garden->display();
    garden->cloneTree(3);
    garden->display();
    garden->cloneTree(1);
    garden->display();
    garden->cloneTree(8);
    garden->display();
    garden->getTreePointer(3)->cutTree(1);
    garden->display();
    garden->getTreePointer(1)->cutTree(5);
    garden->display();
    garden->extractTree(3);
    garden->display();
    garden->harvestGarden(2);
    garden->display();
    garden->getTreePointer(2)->growthTree();
    garden->display();
    garden->getTreePointer(2)->growthTree();
    garden->display();
    garden->fadeGarden();
    garden->display();
    delete garden;
    
    return 0;
}
*/
