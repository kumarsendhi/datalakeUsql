""" 
Dependencies:
Python: Version "3.6.0"
Pandas: Version "0.22.0"
Numpy: Version >= "1.9.0" 

This module contains helper methods:
1. Create data frame from the whole rowset or specified number of rows at a time
2. Create enumerable of output rows from data frame
"""
import sys
import numpy
import pandas

import pyadla

def RowsetToDataframe(rowset, maxRows):
    """Take input rowset and convert requested number of rows to data frame.
    If user want to get single data frame from entire rowset, 'maxRows' 
    should be set to -1 (or any negative number).

    Parameters:
        'rowset': type 'pyadla.Rowset'
        'maxRows': type 'int'
    Note, there is no default value for maxRows argument.

    Returns:
        type 'pandas.DataFrame'
    """
    # create data frame labels
    labels = [column.Name for column in rowset.Schema]

    # user asked for all rows to be in single frame
    # set row count as max possible int
    if maxRows < 0:
        maxRows = sys.maxsize

    # iteratively adding rows to dataFrame is very inefficient,
    # better solution is to append all rows to a list,
    # then create the dataFrame from the list at once.
    rowList = []
    for row in rowset:
        if len(rowList) < maxRows:
            rowData = [value for value in row]
            # add created row to rowList
            rowList.append(rowData)
            if len(rowList) == maxRows:
                break

    # create data frame from rowList
    dataFrame = pandas.DataFrame(
        data=rowList, 
        index=range(len(rowList)), 
        columns=labels )
    return dataFrame

def DataFrameToRowset(dataFrame, outputRow):
    """ Take output data frame and convert it into Enumerable of output rows.
    Parameters:
        'dataFrame': type 'pandas.DataFrame'
        'outputRow': type 'pyadla.OutputRow'

    Returns:
        type 'pyadla.Rowset'
    """

    # columns in dataframe may be not in the same order as in output row schema
    # build the indexes map between dataframe and output row
    indexMap = [outputRow.Schema.IndexOf(columnName) for columnName in dataFrame.columns.values]
    # create outputRow from every single row of data frame.
    for index in range(len(dataFrame)):
        # for every column within row
        for columnIndex in range(len(dataFrame.columns)):
            value = dataFrame.iloc[index, columnIndex]
            # if column value's type is numpy.generic, convert it to 
            # corresponding Python type, to ease setting 
            # value in row extension class
            if isinstance(value, numpy.generic):
                value = numpy.asscalar(value)
            # put column values into output row
            outputRow[indexMap[columnIndex]] = value
        yield outputRow
