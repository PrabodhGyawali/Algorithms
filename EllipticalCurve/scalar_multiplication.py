def bits(n) :
    """
    Generates the binary digits of n, starting from the least significant bit.

    bits(420) -> 1, 1, 0, 1, 0, 0, 1, 0, 0 
    """
    while n:
        yield n & 1
        n >>= 1

def double_and_add(n, x):
    """
    Returns the result of n*x, computed using the double-and-add algorithm.
    """
    result = 0
    addend = x
    for bit in bits(n):
        if bit == 1:
            result += addend
        addend *= 2
    
    return result

"""
Assuming doubling and adding have O(1) time complexity
The time complexity of this algorithm is O(log n) or O(k) - where k is the number of bits in n
"""