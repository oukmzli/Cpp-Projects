class BRANCH_CLASS;

class FRUIT_CLASS {
private:
    unsigned int weight;
    unsigned int growthLenght;
    BRANCH_CLASS* branch;
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;
public:
    FRUIT_CLASS();
    FRUIT_CLASS(const FRUIT_CLASS&);
    FRUIT_CLASS(BRANCH_CLASS*);
    ~FRUIT_CLASS();
    
    unsigned int getLength(void);
    unsigned int getWeight(void);
    
    void growthFruit(void);
    void fadeFruit(void);
    void pluckFruit(void);
    
    BRANCH_CLASS* getBranchPointer(void);
    
    void setLenght(unsigned int);
    void addWeight(unsigned int);
    FRUIT_CLASS* getNext(void);
    FRUIT_CLASS* getPrev(void);
    void setNext(FRUIT_CLASS*);
    void setPrev(FRUIT_CLASS*);
    void setBranch(BRANCH_CLASS*);
    
    //void display();
};
