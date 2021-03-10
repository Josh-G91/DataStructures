//
//  BubbleSort.h
//  CSIT832#3
//
//  Created by Joshua Gonzalez on 11/22/16.
//  Copyright © 2016 Joshua Gonzalez. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h
struct courseDataBub
{
    
    int courseNum;
    int sectionNum;
    
};
class Bubble
{
    
private:
    courseDataBub* course;
    
public:
    Bubble();
    void BubbleSort();
    void printSortedList();
    
    
};
#endif /* BubbleSort_h */
