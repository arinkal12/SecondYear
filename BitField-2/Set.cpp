#include "Set.h"

Set::Set(size_t mp){
    _maxPower = mp;
    _bitField = BitField(mp);
};

Set:: Set(const Set& set){
    _maxPower = set._maxPower;
    _bitField = set._bitField;
};
Set::Set(const BitField& bf){
    _maxPower = bf.GetLength();
    _bitField = bf; 
};

Set::operator BitField(){
    return _bitField;

};

size_t Set::GetMaxPower(){
    return _maxPower;
};

bool Set::operator==(const Set& tmp) { 
        return _maxPower == tmp._maxPower && _bitField == tmp._bitField; 
};

Set& Set::operator=(const Set& tmp) { 
        if (this != &tmp) {
            _maxPower = tmp._maxPower; 
            _bitField = tmp._bitField;
        }
        return *this; 
};

Set& Set::operator~() { 
        _bitField = ~_bitField; 
        return *this;
};