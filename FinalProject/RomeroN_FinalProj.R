#   LOAD PACKAGES   #########################################################

#   Load more packages with pacman
pacman::p_load(pacman, dplyr, ggplot2, forecast, scico, rio, tidyverse, tidyr)
#   Convert/prep scientific notation to legible number
options(scipen=999)

#   IMPORT/PROVISION DATA   #########################################################

#   Data obtained from a Covid-19 tracking project at https://covidtracking.com/

#   Get State Level Data - Import data with rio
statedata <- rio::import("~/.../FinalProject/data/daily.csv")
#   Get County Level Data - Import data with rio
countydata <- rio::import("~/.../FinalProject/data/nc-death-by-county.csv")

#   Date is a native integer, use lubridate to convert attributes to date objects
#   This will later support Timeseries plots and Linear Model forecasting
statedata$date <- lubridate::ymd(statedata$date)

#   Filter data by the state for Family Physician
state <- filter(statedata, state %in% c("NC"))
#   Filter data by all surrounding Counties for Family Physician practicing in Iredell Co. NC
county <- filter(countydata, County %in% c("Iredell", "Cabarrus", "Catawba", "Davie", "Lincoln", "Mecklenburg", "Rowan", "Wilkes", "Yadkin"))

#   Filter data to compare county area cases per 10,000 Residents vs. Overall Mortality
countyCorr <- tidyr::pivot_longer(county, cols=c('Cases Per 10,000 Residents', 'Deaths'), names_to='variable', values_to="value")
head(countyCorr)

#   Store only quantitative fields for Multiple Regression Analysis
analysis <- state %>% 
    dplyr::select(where(is.numeric)) #easiest way -- I found -- to capture only quantitative variables


#   DATA VISUALIZATION   #########################################################

#   Daily Positive Case Increase Boxplot w/ added options
#   Display Confidence Interval for Median of Positive Cases
state %>%
    select(positiveIncrease) %>%
    boxplot(
        horizontal = T,
        notch  = T, # Confidence interval
        main   = "Boxplot of Daily Positive Increase for the State of North Carolina",
        ylab   = "Confidence Interval for Median",
        xlab   = "Number of Positive Cases",
        col    = "red"
    )

#   Neighboring County Case comparison Barchart
ggplot(county, aes(x=County, y=Cases, fill = Cases)) + 
    geom_col() +
    labs(title = "NC Cases by County: Iredell Co. and Immediate Neighboring Counties") +
    labs(fill = "Reported Case Volume") +
    labs(x = "County", y = "Number of Cases") +
    scale_fill_scico(palette = "berlin")

#   Neighboring County Cases per 10k Residents and Mortality Barchart
ggplot(countyCorr, aes(x=County, y=value, fill=variable)) +
    geom_bar(stat='identity', position='dodge') +
    labs(title = "Iredell Co. NC and Immediate Neighboring Counties: Cases per 10k Residents vs. Deaths") +
    labs(fill = "Variable") +
    labs(x = "County", y = "Number of Cases / Deaths")

#   Display Timeseries of Daily Positive Increase
#   Forecast to help answer the question of 'trends with spread' or positive cases
ggplot(state, aes(x = date, y = positiveIncrease, color = state)) +
    geom_line() +
    geom_point() +
    theme_minimal() +
    xlim(as.Date("2020-03-04"), as.Date("2021-02-25")) +
    stat_smooth(method="lm", fullrange=TRUE, fill="black", colour="black", alpha = 0.2) +
    ggtitle("North Carolina 9 Mo. Daily Positive Case Increase with 90 Day Trend Forecast") +
    labs(colour = "State") +
    xlab('Date') +
    ylab('Number of Daily Positive Cases')

#   Display Timeseries of Daily Death Increase
#   Forecast to help answer the question of 'trends with mortality'
ggplot(state, aes(x = date, y = deathIncrease, color = state)) +
    geom_line() +
    geom_point() +
    theme_minimal() +
    xlim(as.Date("2020-03-04"), as.Date("2021-02-25")) +
    stat_smooth(method="lm", fullrange=TRUE, fill="black", colour="black", alpha = 0.2) +
    ggtitle("North Carolina 9 Mo. Daily Mortality Increase with 90 Day Trend Forecast") +
    labs(colour = "State") +
    xlab('Date') +
    ylab('Daily Death Toll')

#   Display Timeseries of Total Hospitalizations
#   Forecast to help answer the question of 'trends with hospitalizations'
ggplot(state, aes(x = date, y = hospitalizedCurrently, color = state)) +
    geom_line() +
    geom_point() +
    theme_minimal() +
    xlim(as.Date("2020-03-04"), as.Date("2021-02-25")) +
    stat_smooth(method="lm", fullrange=TRUE, fill="black", colour="black", alpha = 0.2) +
    ggtitle("North Carolina 9 Mo. Hospitalization Totals with 90 Day Trend Forecast") +
    labs(colour = "State") +
    xlab('Date') +
    ylab('Number of Hospitializations')

ggplot() +
    geom_line(data = state, aes(x = date, y = positiveIncrease, color = "Daily Positives", na.rm = T)) +
    geom_line(data = state, aes(x = date, y = hospitalizedCurrently, color = "Currently Hospitalized", na.rm = T)) +
    geom_line(data = state, aes(x = date, y = inIcuCurrently, color = "in Intensive Care (ICU)", na.rm = T)) +
    geom_line(data = state, aes(x = date, y = deathProbable, color = "Probable Deaths", na.rm = T)) +
    geom_point() +
    theme_minimal() +
    ggtitle("North Carolina Daily Positives, Hospitalization, ICU, and Probable Deaths 9 Month Overlay") +
    labs(color = "Legend: NC Overlay") +
    xlab('Date') +
    ylab('Frequency / Volume')

ggplot() +
    geom_line(data = state, aes(x = date, y = totalTestResultsIncrease, color = "Daily Test Results", na.rm = T)) +
    geom_line(data = state, aes(x = date, y = positiveIncrease, color = "Daily Positives Reported", na.rm = T)) +
    #   geom_line(data = state, aes(x = date, y = hospitalizedCurrently, color = "Currently Hospitalized", na.rm = T)) +
    #   geom_line(data = state, aes(x = date, y = recovered, color = "Total Recovered", na.rm = T)) +
    geom_point() +
    theme_minimal() +
    ggtitle("North Carolina Daily Testing Influx and Daily Positives Reported 9 Month Overlay") +
    labs(color = "Legend: NC Overlay") +
    xlab('Date') +
    ylab('Totals / Count')


#   REGRESSION ANALYSIS   #########################################################


#   Bivariate Regression Analysis   ------------------------------ 


#   Simple/obvious correlation between increased testing and positive cases in NC  
state %>%
    select(totalTestResultsIncrease, positiveIncrease) %>%
    plot(
        main = "Scatterplot correlation between NC Daily PCR Test Result Increase and Daily Positive Case Increase",
        xlab = "Daily Test Result Increase",
        ylab = "Daily Positives Reported Increase"
    )

#   Add regression line with lm() linear model
lm(state$positiveIncrease ~ state$totalTestResultsIncrease) %>% abline()

#   Compute linear model and store 
testFit <- lm(state$totalTestResultsIncrease ~ state$positiveIncrease)

#   Display regression model
testFit
summary(testFit)
#   Check confidence intervals/coefficients
confint(testFit)
#   Predict TestResultsIncrease
predict(testFit)
#   Find intervals in TestResultsIncrease
predict(testFit, interval = "prediction")
#   Measure of influence
lm.influence(testFit)
#   Influence of individual observations on coefficients
influence.measures(testFit)


#   Multiple Regression Analysis    ------------------------------


analysis %>%
    select(hospitalizedCurrently, everything()) %>% # (y, x1, x2, x3...)
    print()

#   I can run a Linear Model a few different ways...

#   Concise but looks at incomplete data as Linear Model
#   Doesn't work b/c the dataset contains N/As or NULL data
#       lm(analysis)

#   Identify outcome, infer rest
#   Dot (.) denotes everyother variable in a dataset
#   Doesn't work b/c dataset contains N/As or NULL data
#       lm(totalTestResultsIncrease ~ ., data = analysis)


#   Design/compute linear model and store
testFit2 <- lm(hospitalizedCurrently ~ 
                positive + probableCases + negative + 
                totalTestResults + totalTestResultsIncrease + inIcuCurrently + 
                recovered + death + totalTestsViral + positiveCasesViral + 
                deathConfirmed + deathProbable + totalTestsAntigen + 
                positiveIncrease + negativeIncrease + deathIncrease + posNeg, 
           data = analysis)

#   Display regression model
testFit2
summary(testFit2)
#   Check confidence intervals/coefficients
confint(testFit2)
#   Predict 
predict(testFit2)
#   Find intervals 
predict(testFit2, interval = "prediction")

#   Store predictions
projectedhospitalizations <- predict(testFit2, interval = "prediction")
#   Convert predictions to a dataframe matrix
predictHospitalization <- as.data.frame(projectedhospitalizations)
#   Give the dataframe a day index
predictHospitalization <- tibble::rowid_to_column(predictHospitalization, "day")

ggplot() +
    geom_line(data = predictHospitalization, aes(x = day, y = fit, color = "Fit", na.rm = T)) +
    geom_line(data = predictHospitalization, aes(x = day, y = lwr, color = "Lower Confidence", na.rm = T)) +
    geom_line(data = predictHospitalization, aes(x = day, y = upr, color = "Upper Confidence", na.rm = T)) +
    geom_point() +
    theme_minimal() +
    ggtitle("North Carolina Multiple Regression Predict Hospitalizations") +
    labs(color = "Legend") +
    xlab('Days Forward') +
    ylab('Number Hospitalized')

#   Measure of influence
lm.influence(testFit2)
#   Influence of individual observations on coefficients
influence.measures(testFit2)


#   MOP UP  #########################################################


#   Clean environment
rm(list = ls())
#   Uninstall packages
p_unload(all)
#   Remove plots
dev.off()  # do only if a plot exists
#   Clear the console
cat("\014")   # command shortcut ctrl+L
