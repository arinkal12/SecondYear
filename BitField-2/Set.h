#include "BitField"

class Set
{
private:

    bitand _bitField;
    size_t _maxPower;
    
public:
    Set(size_t mp);
    Set(const Set& set);// copy
    Set(const BitField& bf);
    operator BitField();
};

