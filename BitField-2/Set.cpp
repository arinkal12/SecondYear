#include "Set.h"


Set::Set(size_t mp) : _bitField(10) {
    _maxPower=mp;
}
Set::Set(const Set &s) : _bitField(10){
    _maxPower = s._maxPower;
    _bitField = s._bitField;
} 
Set::Set(const BitField &bf) : _bitField(10){
    _bitField = bf;
    _maxPower = bf.GetLength();
}

void Set::InsElem(const uint64_t Elem) { 
    if (Elem < _maxPower) { 
        _bitField.SetBit(Elem); 
    }
}
void Set::DelElem(const uint64_t Elem) { 
    if (Elem < _maxPower) {
        _bitField.ClrBit(Elem); 
    }
}
bool Set::IsMember(const uint64_t Elem) const { 
    if (Elem < _maxPower) { 
        return _bitField.GetBit(Elem); 
    }
    return false; 
}


bool Set::operator== (const Set &s) const{
    return _maxPower == s._maxPower && _bitField == s._bitField;
}

bool Set::operator!= (const Set &s) const{
    return !(*this == s);
}


Set& Set::operator=(const Set& s) { 
        if (this != &s) {
            _maxPower = s._maxPower; 
            _bitField = s._bitField;
        }
        return *this; 
}

Set Set::operator+ (const uint64_t Elem){
    return *this;
}
                                  
Set Set::operator- (const uint64_t Elem){
    return *this;
}
                                   
Set Set::operator+ (const Set &s){
    return *this;
}
Set Set::operator* (const Set &s){
    return *this;
}
Set Set::operator~ (){
    return *this;
}
std::vector<uint64_t> Set::GetPrimary(){
    return std::vector<uint64_t>();
}
/*std::vector<uint64_t> Set::GetPrimary(){
    std::vector<uint64_t> prost;
    Set copy(*this); // Создаем копию текущего сета
    
    size_t size_copy = copy.GetMaxPower(); 

    for (size_t i = 2; i < size_copy; ++i) {
        if (copy._bitField.GetBit(i)) { 
            prost.push_back(i); 
            for (size_t j = i * i; j < size_copy; j += i) {
                copy.DelElem(j);
            }
        }
    }
    
    return prost;
}*/