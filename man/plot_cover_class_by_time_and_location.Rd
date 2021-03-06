% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/plotting_functions.R
\name{plot_cover_class_by_time_and_location}
\alias{plot_cover_class_by_time_and_location}
\title{Plot Cover class over space and time}
\usage{
plot_cover_class_by_time_and_location(
  data,
  species,
  datetime_col,
  location_col,
  species_col = .data$Species,
  cover_class_col = .data$`Cover Class`
)
}
\arguments{
\item{data}{Dataframe in long format}

\item{species}{Name of Species to Plot}

\item{datetime_col}{Name of Datetime Column (Default: Datetime)}

\item{location_col}{Name of Location Column (Default: Location)}

\item{species_col}{Name of Species Column (Default: Species)}

\item{cover_class_col}{Name of Cover Class Column (Default: Cover Class)}
}
\value{
ggplot2 object
}
\description{
First found in Ito 2020
}
