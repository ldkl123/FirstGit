#!/usr/bin/env python
import numpy as np



value = [[0.0]* 5 for _ in range(5)]   #2-dimential 


policy_table = [[[0.25, 0.25, 0.25, 0.25]] * 5
                                    for _ in range(5)]

print(value)

policy_table[2][2] = []
value[2] = []  #delete 3nd col

print("\n")
print(value)

# test about the list
