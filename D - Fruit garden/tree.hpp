class GARDEN_CLASS;
class BRANCH_CLASS;

class TREE_CLASS {
private:
    unsigned int treeId;
    unsigned int treeHeight;
    unsigned int totalBranches;
    unsigned int totalFruits;
    unsigned int totalWeight;
    GARDEN_CLASS* garden;
    TREE_CLASS* next;
    TREE_CLASS* prev;
    BRANCH_CLASS* head;
    BRANCH_CLASS* last;
public:
    TREE_CLASS();
    TREE_CLASS(const TREE_CLASS& other);
    TREE_CLASS(GARDEN_CLASS*, unsigned int);
    ~TREE_CLASS();
    
    unsigned int getBranchesTotal(void);
    unsigned int getFruitsTotal(void);
    unsigned int getWeightsTotal(void);
    
    unsigned int getNumber(void);
    unsigned int getHeight(void);
    
    void growthTree(void);
    void fadeTree(void);
    void harvestTree(unsigned int);
    void cutTree(unsigned int);
    
    void cloneBranch(BRANCH_CLASS*);
    
    GARDEN_CLASS* getGardenPointer(void);
    BRANCH_CLASS* getBranchPointer(unsigned int);
    
    TREE_CLASS* getNext(void);
    TREE_CLASS* getPrev(void);
    void setNext(TREE_CLASS*);
    void setPrev(TREE_CLASS*);
    void setGarden(GARDEN_CLASS*);
    void setTreeId(unsigned int);
    
    void addHeight(unsigned int);
    void addBranches(unsigned int);
    void addFruits(unsigned int);
    void addWeight(unsigned int);
    
    void reduceHeight(unsigned int);
    void reduceBranches(unsigned int);
    void reduceFruits(unsigned int);
    void reduceWeight(unsigned int);
    
    //void display();
};
