# Install the package Car, Corrplot and PerformanceAnalytics first
library(corrplot)
library("PerformanceAnalytics")
library(car)

#   Load more packages with pacman
pacman::p_load(pacman, dplyr, rio, xlsx, tidyverse)

options(scipen = 999)

#   Data obtained from a Covid-19 tracking project at https://covidtracking.com/
#   Import data with rio
data <- rio::import("~/.../FinalProject/data/daily.csv")

#   Date is a native integer, use lubridate to change attributes to year, mo, day date objects
data$date <- lubridate::ymd(data$date)

#   Filter data by the state of North Carolina
state <- filter(data, state %in% c("NC"))

#   transform/mutate data variables/cols    ####################

nccovid.data <- state %>%
    mutate(
        y  = (positive),
        x1 = (hospitalizedCurrently),
        x2 = (recovered),
        x3 = (death)
    ) %>%
    select(y, x1, x2, x3)
attach(nccovid.data)
write.xlsx(state, "~/.../FinalProject/data/nc-covid-project.xlsx")


#   Individual variable corr test (i.e., positive vs. death)
cor.test(nccovid.data$y, nccovid.data$x2)
#   Individual variable corr test (i.e., hospitalizedCurrently vs. recovered)
cor.test(nccovid.data$x1, nccovid.data$x2)
#   Individual variable corr test (i.e., hospitalizedCurrently vs. death)
cor.test(nccovid.data$x1, nccovid.data$x3)

# Get the correlation matrix
res <- cor(cbind(y,x1,x2,x3))
#   Round to dec places
round(res, 2)

# Plot the correlations
corrplot(res, type = "upper", order = "hclust", 
         tl.col = "black", tl.srt = 45)

# Get some colors
col<- colorRampPalette(c("blue", "white", "red"))(20)
heatmap(x = res, col = col, symm = TRUE)
my_data <- nccovid.data[, c(2,3,4)]
chart.Correlation(my_data, histogram=TRUE, pch=19)

# Build the OLS Regression Model
nccovid.model <- lm(y~x1 + x2 + x3)
summary(nccovid.model)

# get confidence intervals for the regression coefficients
confint(nccovid.model)

# get the variance inflation factors
vif(nccovid.model)
newdata = data.frame(x1=000000, x2=0.0, x3=0)
# Specify data.frame model x1, x2, x3 snapshots ####################

predict(nccovid.model, newdata, interval="predict") 
predict(nccovid.model, newdata, interval="confidence")


#   MOP UP  ###################

#   Clean environment
rm(list = ls())

#   Uninstall packages
p_unload(all)

#   Remove plots
dev.off()  # do only if a plot exists

#   Clear the console
cat("\014")   # command shortcut ctrl+L
