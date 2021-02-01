#   Load more packages with pacman
pacman::p_load(pacman, dplyr, ggplot2, ggeasy, rio, tidyverse)

#   Data obtained from a Covid-19 tracking project at https://covidtracking.com/
#   Import data with rio
data <- rio::import("~/.../FinalProject/data/daily.csv")

#   Date is a native integer, use lubridate to change attributes to year, mo, day date objects
data$date <- lubridate::ymd(data$date)

#   Filter data by the state of North Carolina
state <- filter(data, state %in% c("NC"))

options(scipen=100000)

ggplot(state, aes(x = date, y = positive, color = state)) +
    geom_line() +
    geom_point() +
    theme_minimal() +
    ggtitle("North Carolina Daily Covid-19 Cases")

#   MOP UP  ###################


#   Clean environment
rm(list = ls())

#   Uninstall packages
p_unload(all)

#   Remove plots
dev.off()  # do only if a plot exists

#   Clear the console
cat("\014")   # command shortcut ctrl+L
