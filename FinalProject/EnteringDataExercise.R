# R COMMANDLINE GYMNASTICS   ###################
# Entering Data

# run each line w/ cmd/ctrl enter

# Intro to R Commands       ####################

2+2                 # Basic arithmetic operation

0:100               # Print 1 to 100 several lines

print("Hello World!")

# Individual Vals           ####################
# Saving to Global Env. Memory

A <- 1              # Use <- not = to set things
2 -> B              # Goes either way (not a best practice)
c <- d <- e <- 3    # Multiple Assignments

# Multiple Values           #################### 
X <- c(1, 2, 5, 9)  # c means to concatenate
X                   # Print X in Console

# Sequence                  ####################

0:10                # 0 to 10
10:0                # 10 to 0
seq(10)             # 1 to 10
seq(30, 0, by = -3) # Increment down by 3

# Math                      ####################
# Transform numbers

# close commands with parentheses to print
(Y <- c(5, 1, 0, 10))
X + Y               # Add variables
X * 5               # Multipy variables
2^6                 # Raise powers/exponents
sqrt(64)            # Squareroot
log(100)            # Natural log: base e (2.71828...)
log10(100)          # Base 10 log

# Clean                      ####################

# Clear environment
rm(list = ls())

# Clear console
cat("\014")          # ctrl+L

