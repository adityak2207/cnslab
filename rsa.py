# Simple RSA algorithm in python
import math
from math import gcd
from re import M

p = 3
q = 7

n = p*q
e = 2
phi = (p-1)*(q-1)

#Generate a public key
while(e < phi):
    if(gcd(e, phi) == 1):
        break
    else:
        e = e+1

msg = 12.0
c = math.fmod(pow(msg, e), n)
print("Encrypted data : ", c)

#Generate a private key
k = 2
d = (1 + k*phi) / e
m = math.fmod(pow(c, d), n)
print("Decrypted data : ", m)