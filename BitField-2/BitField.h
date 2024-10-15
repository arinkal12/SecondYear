#include <iostream>
#include <stdint.h>

class BitField {
private:
    size_t _sizeBit;
    uint16_t* _mem;
    size_t _memSize;

    size_t GetMemIndex(size_t n) const;
    uint16_t GetMask(size_t n) const;
public:
    BitField(size_t len);
    BitField(const BitField& tmp);
    BitField& operator=(const BitField& tmp);
    BitField() : _sizeBit(0), _memSize(0), _mem(nullptr) {} 
    
    size_t GetLength() const; // Получить количество бит
    void SetBit(size_t n);
    void ClrBit(size_t n); // Настя
    uint8_t GetBit(size_t n) const; // Саша


    BitField operator|(const BitField& tmp); // Карина
    BitField operator&(const BitField& tmp); // Алина
    BitField operator^(const BitField& tmp); // Арина
    bool operator==(const BitField& tmp); // Даша
    BitField operator~(); // Все

    ~BitField(); // Все
};