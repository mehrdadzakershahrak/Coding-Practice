def minFlips(self, a: int, b: int, c: int) -> int:
    flips = 0
    while a > 0 or b > 0 or c > 0:
        # Get the last bit of a, b, c
        a_bit = a & 1
        b_bit = b & 1
        c_bit = c & 1

        # If c's current bit is 1 but neither a nor b has a 1 in the current bit position,
        # we need one flip.
        if c_bit == 1 and a_bit == 0 and b_bit == 0:
            flips += 1
        # If c's current bit is 0 but either a or b (or both) has a 1 in the current bit position,
        # we need to flip those bits.
        elif c_bit == 0:
            flips += a_bit + b_bit

        # Right shift a, b, c to process the next bit
        a = a >> 1
        b = b >> 1
        c = c >> 1

    return flips