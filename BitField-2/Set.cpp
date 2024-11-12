#include "Set.h"
#include "BitField.h"
#include <vector>

Set::Set(size_t mp) : _bitField(mp) {//задаем макс мощьность множества
    _maxPower=mp;
}
Set::Set(const Set &s) : _bitField(s._bitField){// констуктор копирваония 
    _maxPower = s._maxPower;
    _bitField = s._bitField;
} 
Set::Set(const BitField &bf) : _bitField(bf){
    _maxPower = bf.GetLength();// макс мщ = размаеру бит поля 
}

void Set::InsElem(const uint64_t Elem) {  // вставить элемент 
    if (Elem < _maxPower) { 
        _bitField.SetBit(Elem); // уставновкаа бмта соответс эл
    }
}
void Set::DelElem(const uint64_t Elem) { // удалить элемент 
    if (Elem < _maxPower) {
        _bitField.ClrBit(Elem); // сброс бита для соотв эл
    }
}
bool Set::IsMember(const uint64_t Elem) const { 
    if (Elem < _maxPower) { 
        return _bitField.GetBit(Elem); 
    }
    return false; 
}


bool Set::operator== (const Set &s) const{
    return  _bitField == s._bitField;
}

bool Set::operator!= (const Set &s) const{
    return !(_bitField==s._bitField);
}


Set& Set::operator=(const Set& s) { 
        if (this != &s) {// проверка на равенство друг другу 
            _maxPower = s._maxPower; 
            _bitField = s._bitField;
        }
        return *this; 
}


Set Set::operator+ (const uint64_t Elem) {// объед
    Set res(*this);
    res.InsElem(Elem);
    return res;
}

Set Set::operator- (const uint64_t Elem) {//разность 
    Set res(*this);
    res.DelElem(Elem);
    return res;
}

Set Set::operator+ (const Set &s) {//обьед
    return _bitField | s._bitField;
}

Set Set::operator*(const Set& tmp){// пересеч 
    return _bitField & tmp._bitField;
};

Set Set::operator~ () {// дополнение
    Set result(_maxPower);
    for (size_t i = 0; i < _maxPower; ++i) {
        if (!IsMember(i)== true) {// тек эл не входит то добовлем его 
            result.InsElem(i);
        }
    }
    return result;
}

std::vector<uint64_t> Set::GetPrimary() {
    std::vector<uint64_t> prost;
    Set copy(*this);
    size_t size_copy = copy.GetMaxPower();
    prost.push_back(1);
    for (size_t i = 2; i < size_copy; ++i) {
        if (copy.IsMember(i) == true) {
            prost.push_back(i);
            for (size_t j = i * i; j < size_copy; j += i) {
                copy.DelElem(j);
            }
        }
    }
    return prost;
}

size_t Set::GetMaxPower(void) const {
    return _maxPower;
}

