#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{//возвращает индекс эл соотвеств биту номером н
    if (n >= _sizeBit)
        throw "Bit out of range!";
    return n / (8 * sizeof(uint16_t));
}
uint16_t BitField::GetMask(size_t n) const {//создаем маску
     return 1 << (n % (8 * sizeof(uint16_t)));
}


BitField::BitField(size_t len) {// констуктор иницализируюзий  битфилд с заданным кол-вом бит 
    _sizeBit = len;
    _memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {// конструкор копирования 
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[_memSize];
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
}

BitField& BitField::operator=(const BitField& tmp){
    if (_sizeBit != tmp._sizeBit){
        delete [] _mem;
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        _mem = new uint16_t[_memSize];
    }
    for (size_t i = 0; i < _memSize; ++i)
        _mem[i] = tmp._mem[i];
    return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}
void BitField::SetBit(size_t n) {//1
    _mem[GetMemIndex(n)] |= GetMask(n);
}
void BitField::ClrBit(size_t n){//0
     _mem[GetMemIndex(n)] &= ~GetMask(n);

}
uint8_t BitField::GetBit(size_t n) const {//и
    if (n >= _sizeBit)
        throw "Bit out of range!";
    int k =  _mem[GetMemIndex(n)] & GetMask(n); // зануляем все биты кроеме нужного
    if (k!=0){
        return true;
    }
    else{
        return false;
    }
}

BitField BitField::operator|(const BitField& tmp){//или
    BitField res(_sizeBit);
        for (size_t i = 0; i < _memSize; ++i) {
            res._mem[i] = _mem[i] | tmp._mem[i];
        }
        return res;

}

BitField BitField::operator&(const BitField& tmp){//и
    BitField res(_sizeBit);
        for (size_t i = 0; i < _memSize; ++i) {
            res._mem[i] = _mem[i] & tmp._mem[i];
        }
        return res;

}

BitField BitField::operator^(const BitField& tmp){// хор
    BitField res(_sizeBit);
        for (size_t i = 0; i < _memSize; ++i) {
            res._mem[i] = _mem[i] ^ tmp._mem[i];
        }
        return res;

}


bool BitField::operator==(const BitField& tmp) const{
    for (size_t i = 0; i < _memSize; ++i) {
        if (_mem[i] != tmp._mem[i]) {
            return false;
        }
    }
    return true;
}

BitField BitField::operator~(){
    BitField res = BitField(*this);
    for (int i = 0; i < _sizeBit; i++){
        if (GetBit(i)== true){
            res.ClrBit(i);
        }
        else{
            res.SetBit(i);
        }
    }
    return res;
}

