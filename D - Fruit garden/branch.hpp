class TREE_CLASS;
class FRUIT_CLASS;

class BRANCH_CLASS {
private:
    unsigned int branchLength;
    unsigned int branchHeight;
    unsigned int totalFruits;
    unsigned int totalWeights;
    TREE_CLASS* tree;
    BRANCH_CLASS* next;
    BRANCH_CLASS* prev;
    FRUIT_CLASS* head;
    FRUIT_CLASS* last;
public:
    BRANCH_CLASS();
    BRANCH_CLASS(const BRANCH_CLASS&);
    BRANCH_CLASS(TREE_CLASS*, unsigned int);
    ~BRANCH_CLASS();
    
    unsigned int getFruitsTotal(void);
    unsigned int getWeightsTotal(void);
    unsigned int getHeight(void);
    unsigned int getLength(void);
    
    void growthBranch(void);
    void fadeBranch(void);
    void harvestBranch(unsigned int);
    void cutBranch(unsigned int);
    
    FRUIT_CLASS* getFruitPointer(unsigned int);
    TREE_CLASS* getTreePointer(void);
    
    void setNext(BRANCH_CLASS*);
    void setPrev(BRANCH_CLASS*);
    BRANCH_CLASS* getNext(void);
    BRANCH_CLASS* getPrev(void);
    void setTree(TREE_CLASS*);
    
    void addLength(unsigned int);
    void addHeight(unsigned int);
    void addFruits(unsigned int);
    void addWeight(unsigned int);
    
    void reduceLength(unsigned int);
    void reduceHeight(unsigned int);
    void reduceFruits(unsigned int);
    void reduceWeight(unsigned int);
    
    void setHeight(unsigned int);
    
    //void display();
};
