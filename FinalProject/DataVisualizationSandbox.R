# INSTALL AND LOAD PACKAGES   ###################
# all commands can be executed line-by-line with cmd+return on Mac

# Load more packages with pacman
pacman::p_load(pacman, rio, tidyverse)
# pacman: loads/unloads packages 
# rio: for importing data, tidyverse: as a best practice


# LOAD AND PREPARE NC COVID DATA   ###################


# Save data as 'data frame' with 'df'
# Name the result 'output' or whatever
# Show the result 'output' with df$output

# Import CSV files with readr::read_csv() from tidyverse
(dataset <- read.csv("~/.../FinalProject/data/nc-death-by-county.csv"))
print(dataset)

(timeseries <- read.csv("~/.../FinalProject/data/nc-cases-over-time.csv"))
print(dataset)

# browseURL("https://covidtracking.com/data/state/north-carolina") # goes to data source

# Dummy data set for testing
x <- seq(30, 0, by = -3) # Increment down by 3 from 30


# DATA VISUALIZATION   ###################


# browseURL("https://datalab.cc/rcolors") # goes to R color support
# ?colors # offers R documentation on colors
# colors() # list of color names

# There are several ways to define colors, I'm using hexcodes
barplot(x, col = "#CD0000") # red
barplot(x, col = "#9FB6CD") # slategray

# Multiple Color System
# call several colors in a vector that alternate

barplot(x, col = c("red3", "slategray3")) # show red, gray
barplot(x, col = c("#9FB6CD", "#CD0000")) # reverse it

# experiment with palettes
# ?palette # offers R documentation on palettes
# palette() # show curr palette

barplot(x, col = 1:10)                # Use current palette
barplot(x, col = heat.colors(10))     # Yellow through red
barplot(x, col = terrain.colors(10))  # Gray through green
barplot(x, col = topo.colors(10))     # Purple through tan
barplot(x, col = cm.colors(10))       # Pinks and blues


#   BARCHARTS   ###################

#   ?plot # X-Y Plotting
#   ?barplot    #  find out more on the function itself

#   plot(dataset$Cases)

dataset %>%
    select(County) %>%
    table() %>%
    barplot()   # returns error b/c not a vector or matrix

#   Create the vector with table()
#   ?table

#   HISTOGRAM   ###################

#   ?hist   # offers R documentation on histogram

# Histogram with defaults
hist(dataset$Deaths)

# Histogram w/ added options
hist(dataset$Deaths,
     breaks = 7,  # Suggest number of breaks
     main   = "Histogram of Deaths by County",
     sub    = "(Source: ggplot2::dataset)",
     ylab   = "Frequency",
     xlab   = "Number of Deaths in County",
     border = NA,  # No borders on bars
     col    = "#CD0000"  # red3
)

# Boxplot w/ added options
dataset %>%
    select(Deaths) %>%
    boxplot(
     horizontal = F,
     notch  = T, # Confidence interval for median
     main   = "Boxplot of Deaths by County",
     sub    = "(Source: ggplot2::dataset)",
     xlab   = "Number of Deaths in County",
     col    = "#CD0000"  # red3
)

dataset %>%
    select(Deaths, Cases) %>%
    plot()


#   MOP UP  ###################


#   Clean environment
rm(list = ls())

#   Uninstall packages
p_unload(all)

#   Remove plots
dev.off()  # do only if a plot exists

#   Clear the console
cat("\014")   # command shortcut ctrl+L
