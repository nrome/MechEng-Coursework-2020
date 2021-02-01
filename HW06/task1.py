#   --------------------
#   Python - Parse CSV file for fnorm function
#   --------------------

import sys
import numpy as np

fnorm = np.loadtxt(sys.argv[1], delimiter=",")
print("fnorm: ", np.linalg.norm(fnorm))

