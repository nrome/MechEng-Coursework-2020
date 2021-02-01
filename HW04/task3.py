#   --------------------
#   Python - Matrix Vector Multiplication
#   --------------------

import sys
import numpy as np
import math
import time

#   --------------------
#   Declare Vars
#   --------------------

A, b, c = [], [], []

#   --------------------
#   Initialize Vars
#   --------------------

#   Interpret command line argument (assigned by SLURM script)
arg1 = str(sys.argv[1])

#   Similar to atoi in C - convert argument to int
n = int(arg1)

#   Append random attributes to A[...]
for x in range(n * n):
    randVal = round(np.random.uniform(-1.0, 1.0), 7)
    A = np.array([randVal], dtype=np.float)

#   Append attributes to b[...] and c[...] 
for y in range(n):
    b = np.array([1.0], dtype=np.float)
    c = np.array([0.0], dtype=np.float)

#   --------------------
#   Time interval around MVM func
#   --------------------

start = time.time()
c = np.matmul(A, b)
end = time.time()
cpu_time = end - start

#   --------------------
#   Output
#   --------------------

#   Output c product
print("c mvmult:", c)

#   Output time to milliseconds conversion
print("CPU time (ms): {}".format(cpu_time * 1000))
