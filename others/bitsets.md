# Bitset Magic 

A bitset is an array of bools but each boolean value is not stored in a separate byte. Each boolean value takes 1-bit space.

1. Why is bool 1 byte/8 bits?

Ans : C++ data type must be addressable. Pointer cannot point to a individual bit. Byte addressing is an architectural choice. 

2. Is vector<bool> a STL container?

Ans : No, because it takes 1 bit space for bool. In exchange for the optimization it does not offer all the capabilities of standard stl.

BITSET operations

1. bitset<SIZE> v("1111");
2. v.any() : check if any bit is set.
3. v.all(): check if all bits are set.
4. v.test(idx): returns value at given idx.
5. v.set(idx): sets value at given idx.
6. v.reset(idx): unsets value at given idx.
7. v.count(): count number of set bits.
8. v.flip(idx): flips the value at given idx.
9. v.to_string()
10. v.to_ulong()

BITSET supports all boolean operations. 

