def extended_euclidean_algorithm(a, b):
    s, old_s = 0, 1
    t, old_t = 1, 0     # number of steps
    r, old_r = b, a     

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r 
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t

    return old_r, old_s, old_t

print(extended_euclidean_algorithm(54, 24))  # Output: (6, 1, -2)
