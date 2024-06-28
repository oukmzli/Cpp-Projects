#include <stdio.h>
class TREE_CLASS;

class GARDEN_CLASS{
private:
    unsigned int totalTrees;
    unsigned int totalBranches;
    unsigned int totalFruits;
    unsigned int totalWeights;
    unsigned int gap;
    TREE_CLASS* head;
    TREE_CLASS* last;
public:
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    
    unsigned int getTreesTotal(void);
    unsigned int getBranchesTotal(void);
    unsigned int getFruitsTotal(void);
    unsigned int getWeightsTotal(void);
    
    void plantTree(void);
    void extractTree(unsigned int);
    
    void growthGarden(void);
    void fadeGarden(void);
    void harvestGarden(unsigned int);
    
    TREE_CLASS *getTreePointer(unsigned int);
    void cloneTree(unsigned int);
    
    void addTrees(unsigned int);
    void addBranches(unsigned int);
    void addFruits(unsigned int);
    void addWeight(unsigned int);
    
    void reduceTrees(unsigned int);
    void reduceBranches(unsigned int);
    void reduceFruits(unsigned int);
    void reduceWeight(unsigned int);
    
    //void display();
};
