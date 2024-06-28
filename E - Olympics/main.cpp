// Denys Kyrychenko
#include <iostream>
#include <string>

class PLAYER_CLASS {
private:
    virtual void die() = 0;
    
    friend class CAESAR_CLASS;
    friend class ARENA_CLASS;
    friend class SQUAD_CLASS;
    
public:
    unsigned int maxHp;
    unsigned int hp;
    unsigned int damage;
    unsigned int agility;
    PLAYER_CLASS *next;
    PLAYER_CLASS *prev;
    PLAYER_CLASS *squad;
    std::string identifier;
    
    virtual unsigned int getRemainingHealth() {
        return 100 * hp / maxHp;
    }
    
    virtual unsigned getDamage() = 0;
    
    virtual unsigned int getAgility() {
        return agility;
    }
    
    virtual void takeDamage(unsigned int damage) = 0;
    
    virtual void applyWinnerReward() {
        damage += 2;
        agility += 2;
    }
    
    virtual void cure() {
        hp = maxHp;
    }
    
    virtual void printParams() = 0;
    
    virtual std::string getId() = 0;
};

class CAESAR_CLASS {
public:
    unsigned int totalAttacks;
    unsigned int totalJudgements;
    
    CAESAR_CLASS() {
        totalAttacks = 0;
        totalJudgements = 0;
    }
    
    void judgeDeathOrLife(PLAYER_CLASS* player) {
        totalJudgements++;
        if (totalAttacks % 2 == 0 && totalJudgements % 3 == 0) {
            player->die();
        }
    }
    
};

class ARENA_CLASS {
private:
    CAESAR_CLASS caesar;
    
public:
    ARENA_CLASS(CAESAR_CLASS* caesar) {
        this->caesar = *caesar;
    }
    
    void fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2) {
        if (p1->getRemainingHealth() == 0 || p2->getRemainingHealth() == 0) return;
        if (p1->getAgility() < p2->getAgility()) {
            PLAYER_CLASS* temp = p1;
            p1 = p2;
            p2 = temp;
        }
        p1->printParams();
        p2->printParams();
        
        int i = 0;
        while (i < 40 && p1->getRemainingHealth() >= 10 && p2->getRemainingHealth() >= 10) {
            if (i % 2 == 0) {
                p2->takeDamage(p1->getDamage());
                p2->printParams();
            } else {
                p1->takeDamage(p2->getDamage());
                p1->printParams();
            }
            i++;
        }
        caesar.totalAttacks = i;
        
        if (p1->getRemainingHealth() > 0) {
            caesar.judgeDeathOrLife(p1);
            p1->printParams();
            if (p1->getRemainingHealth() > 0) {
                p1->applyWinnerReward();
                p1->cure();
            }
        }
        
        if (p2->getRemainingHealth() > 0) {
            caesar.judgeDeathOrLife(p2);
            p2->printParams();
            if (p2->getRemainingHealth() > 0) {
                p2->applyWinnerReward();
                p2->cure();
            }
        }
        
        p1->printParams();
        p2->printParams();
    }
    
};

class HUMAN_CLASS : virtual public PLAYER_CLASS {
public:
    std::string identifier;
    unsigned int defense;
    
    HUMAN_CLASS() {
        init();
    }
    
    HUMAN_CLASS(std::string id) {
        init();
        identifier = id;
    }

    void init() {
        maxHp = 200;
        hp = 200;
        damage = 30;
        agility = 10;
        defense = 10;
        identifier = "";
        next = NULL;
        prev = NULL;
        squad = NULL;
    }
    
    std::string getId() {
        return identifier;
    }
    
    void die() {
        hp = 0;
    }
    
    unsigned int getDamage() {
        return damage;
    }
    
    void takeDamage(unsigned int damage) {
        if (damage < defense + agility) return;
        
        if (damage >= hp + (defense + agility)) {
            die();
        } else {
            hp -= damage - (defense + agility);
        }
    }
    
    void printParams() {
        if (getRemainingHealth() > 0) {
            std::cout << identifier <<
            ":" << maxHp <<
            ":" << hp <<
            ":" << getRemainingHealth() << "%" <<
            ":" << getDamage() <<
            ":" << agility <<
            ":" << defense << "\n";
        } else {
            std::cout << identifier << ":" << "R.I.P.\n";
        }
    }
};

class BEAST_CLASS : virtual public PLAYER_CLASS {
public:
    std::string identifier;
    
    BEAST_CLASS() {
        init();
    }
    
    BEAST_CLASS(std::string id) {
        init();
        identifier = id;
    }
    
    void init() {
        maxHp = 150;
        hp = 150;
        damage = 40;
        agility = 20;
        identifier = "";
        next = NULL;
        prev = NULL;
        squad = NULL;
    }
    
    std::string getId() {
        return identifier;
    }
    
    void die() {
        hp = 0;
    }
    
    unsigned int getDamage() {
        return getRemainingHealth() < 25 ? damage * 2 : damage;
    }
    
    void takeDamage(unsigned int damage) {
        if (damage < agility / 2) return;
        
        if (damage >= hp + agility / 2) {
            die();
        } else {
            hp -= damage - agility / 2;
        }
    }
    
    void printParams() {
        if (getRemainingHealth() > 0) {
            std::cout << identifier <<
            ":" << maxHp <<
            ":" << hp <<
            ":" << getRemainingHealth() << "%" <<
            ":" << getDamage() <<
            ":" << agility << "\n";
        } else {
            std::cout << identifier << ":" << "R.I.P.\n";
        }
    }
    
};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {
public:
    
    BERSERKER_CLASS() {
        init();
    }
    
    BERSERKER_CLASS(std::string humanId, std::string beastId) {
        init();
        HUMAN_CLASS::identifier = humanId;
        BEAST_CLASS::identifier = beastId;
    }
    
    void init() {
        maxHp = 200;
        hp = 200;
        damage = 35;
        agility = 5;
        defense = 15;
        HUMAN_CLASS::identifier = "";
        BEAST_CLASS::identifier = "";
        next = NULL;
        prev = NULL;
        squad = NULL;
    }
    
    void die() {
        hp = 0;
    }
    
    unsigned int getRemainingHealth() {
        return 100 * hp / maxHp;
    }
    
    bool isHuman() {
        return getRemainingHealth() >= 25 || getRemainingHealth() == 0;
    }
    
    std::string getId() {
        return isHuman() ? HUMAN_CLASS::identifier : BEAST_CLASS::identifier;
    }
    
    unsigned int getDamage() {
        return isHuman() ? HUMAN_CLASS::getDamage() : BEAST_CLASS::getDamage();
    }
    
    void takeDamage(unsigned int damage) {
        isHuman() ? HUMAN_CLASS::takeDamage(damage) : BEAST_CLASS::takeDamage(damage);
    }
    
    void printParams() {
        isHuman() ? HUMAN_CLASS::printParams() : BEAST_CLASS::printParams();
    }
};

class SQUAD_CLASS : public PLAYER_CLASS {
public:
    PLAYER_CLASS *first;
    std::string identifier;
    int memberCount;
    
    SQUAD_CLASS() {
        init();
    }
    
    SQUAD_CLASS(std::string id) {
        init();
        identifier = id;
    }
    
    void init() {
        identifier = "";
        memberCount = 0;
        first = NULL;
        next = NULL;
        prev = NULL;
        squad = NULL;
    }
    
    std::string getId() {
        return identifier;
    }
    
    void addPlayer(PLAYER_CLASS* player) {
        if (player == NULL || player->getRemainingHealth() == 0 || player->squad != NULL) {
            return;
        }
        
        player->squad = this;
        
        if (first == NULL) {
            first = player;
        } else {
            PLAYER_CLASS* last = first;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = player;
            player->prev = last;
        }
        
        memberCount++;
    }
    
    unsigned int getAgility() {
        if (first == NULL) return 0;
        unsigned int min = first->getAgility();
        
        PLAYER_CLASS* current = first->next;
        while (current != NULL) {
            if (current->getAgility() < min) {
                min = current->getAgility();
            }
            current = current->next;
        }
        
        return min;
    }
    
    unsigned int getDamage() {
        if (first == NULL) return 0;
        unsigned int sum = 0;
        
        PLAYER_CLASS* current = first;
        while (current != NULL) {
            sum += current->getDamage();
            current = current->next;
        }
        
        return sum;
    }
    
    unsigned int getRemainingHealth() {
        if (first == NULL) return 0;
        unsigned int max = first->getRemainingHealth();
        
        PLAYER_CLASS* current = first->next;
        while (current != NULL) {
            if (current->getRemainingHealth() > max) {
                max = current->getRemainingHealth();
            }
            current = current->next;
        }
        
        return max;
    }
    
    void takeDamage(unsigned int damageDealt) {
        if (memberCount == 0) return;
        
        PLAYER_CLASS *current = first, *next = NULL;
        unsigned int denominator = memberCount;
        
        while (current != NULL) {
            next = current->next;
            current->takeDamage(damageDealt / denominator);
            
            if (current->getRemainingHealth() == 0) {
                if (current == first) {
                    first = next;
                }
                if (current->prev != NULL) {
                    current->prev->next = next;
                }
                if (next != NULL) {
                    next->prev = current->prev;
                }
                current->squad = NULL;
                memberCount--;
            }
            current = next;
        }
    }
    
    void applyWinnerReward() {
        if (first == NULL) return;
        PLAYER_CLASS *current = first;
        while (current != NULL) {
            current->applyWinnerReward();
            current = current->next;
        }
    }
    
    void cure() {
        if (first == NULL) return;
        PLAYER_CLASS *current = first;
        while (current != NULL) {
            current->cure();
            current = current->next;
        }
    }
    
    void die() {
        while (first != NULL) {
            PLAYER_CLASS *next = first->next;
            first->die();
            first->next = NULL;
            first->prev = NULL;
            
            first = next;
        }
        memberCount = 0;
    }
    
    // p1 < p2
    bool compare(PLAYER_CLASS* p1, PLAYER_CLASS* p2) {
        if (p1->getId() != p2->getId())
            return p1->getId() < p2->getId();
        if (p1->maxHp != p2->maxHp)
            return p1->maxHp < p2->maxHp;
        if (p1->hp != p2->hp)
            return p1->hp < p2->hp;
        if (p1->getRemainingHealth() != p2->getRemainingHealth())
            return p1->getRemainingHealth() < p2->getRemainingHealth();
        if (p1->getDamage() != p2->getDamage())
            return p1->getDamage() < p2->getDamage();
        return p1->getAgility() < p2->getAgility();
    }
    
    void sort() {
        if (first == NULL || first->next == NULL) return;

        PLAYER_CLASS *sorted = NULL;
        PLAYER_CLASS *current = first;

        while (current != NULL) {
            PLAYER_CLASS *next = current->next;
            PLAYER_CLASS *position = sorted;

            while (position != NULL && compare(position, current)) {
                position = position->next;
            }

            if (position == NULL) {
                if (sorted == NULL) {
                    sorted = current;
                    current->prev = NULL;
                } else {
                    PLAYER_CLASS *last = sorted;
                    while (last->next != NULL) {
                        last = last->next;
                    }
                    last->next = current;
                    current->prev = last;
                }
                current->next = NULL;
            } else {
                if (position->prev == NULL) {
                    current->next = sorted;
                    sorted->prev = current;
                    current->prev = NULL;
                    sorted = current;
                } else {
                    position->prev->next = current;
                    current->prev = position->prev;
                    current->next = position;
                    position->prev = current;
                }
            }

            current = next;
        }

        first = sorted;
    }

    
    void printParams() {
        if (memberCount > 0) {
            std::cout << identifier << 
            ":" << memberCount <<
            ":" << getRemainingHealth() << "%" <<
            ":" << getDamage() <<
            ":" << getAgility() << "\n";
            
            sort();
            PLAYER_CLASS *current = first;
            while (current != NULL) {
                current->printParams();
                current = current->next;
            }
        } else {
            std::cout << identifier << ":nemo\n";
        }
    }
    
};
