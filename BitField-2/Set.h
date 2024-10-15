#include "BitField.h"

class Set
{
private:

    BitField _bitField;
    size_t _maxPower;
    
public:
    Set(size_t mp);
    Set(const Set& set);// copy
    Set(const BitField& bf);
    //operator BitField();
    size_t GetMaxPower();
    void InserElem(uint64_t elem);
    void DeleteElem(uint64_t elem);
    bool IsMemder(uint64_t elem);// proverka est elem ili net

    bool operator==(const Set& tmp);
    Set& operator=(const Set& tmp);
    Set& operator+(const Set& tmp);//обьедеинение множеств разной мощности в том числе 
    Set& operator-(uint64_t elem);// добавления эелементов 
    Set& operator*(const Set& tmp);// пересечение 
    Set& operator~(); // доплнение к основному множеству

    friend std::istream& operator>>(std::istream& istr, Set& set);
    friend std::istream& operator<<(std::istream& istr, const Set& set);

};

