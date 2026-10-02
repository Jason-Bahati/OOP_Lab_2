# CSCI 1260 - Labs: hierarchy and contracts

Jason Bahati
Section - 002
Track A - The Shop (River City Supply)

Language: C++

How to run program:

I have provided a Makefile that should compile both parts of the lab.
In a terminal, type and enter "make all" then enter:
"./hierarchy" to run the hierarchy driver
"./contracts" to run the contracts driver

================Lab 2 Hierarchy Questions=================================


1.) PhysicalGood has real code in it and still cannot be built. Why is that the right call? What would
break if you made it concrete and let somebody write new PhysicalGood(...) ?
    
    - Because it inherits Category() and HandlingFee() StockItem, which are pure virtual functions
    it's the right call because PhysicalGood doesn't know what kind of item it is. If it were concrete,
    someone could make a random physical good that could misrepresent what it actually is

2.)Your program has two diamonds and only one of them is filled. Explain both. For each
relationship, say who creates the object and what survives what. Then answer the harder half: if Add
were changed so that Shop took a Sku, a name, a price, and a quantity and built the record itself,
which diamond would change, and would that be an improvement or a mistake?

    - Shops holds StockItem pointers - hollow diamond - aggregation
    main builds every record with new and hands the object to Add. The record exists before shop sees it
    and would still be valid if shop didn't exist

    - StockItem holds StockMovement objects - filled diamond, composition.
    A movement is only ever built inside Receive/Release, nothing outside the record ever holds or
    builds one, so when record is gone, it's movements go too

    - If Add took raw fields and built the record itself, the hollow diamond would be a filled diamond.
    shop would be the record maker and not main, it would be a mistake because main would lose the ability
    to build or check a record before deciding what shop it belongs to.

3.)A rental kind is coming next term. It has bulk, it goes on sale, and it charges a deposit. Name
every file you would create and every existing file you would edit. If your answer includes Shop.cs,
explain why, because the target answer is that Shop does not change at all. Then finish with this:
DurableGood signs no interface, and the rental kind will sign IDiscountable . What would have
gone wrong if IsOnSale had been declared on StockItem instead of in a contract

    - I would Add in the file pair RentalGood.h and RentalGood.cpp. It would extend PhysicalGood and
    Implement IDiscountable. no existing file would change, including shop because it stores StockItem pointer
    calls virtual methods through that base pointer, and checks for IDiscountable with dynamic_cast. all of that works
    on any new leaf without having to edit shop.
    if IsOnSale had been declared on StockItem instead of in a contract, then every leaf would have been forced to implement
    that, including DurableGood which is supposed to never go on sale

================Lab 3 Contract Question=================================

1.)Record 5 carries the same key as record 1 and a different measurement, and this lab calls them
equal. Name one situation where that is the right call and one where it would be a bug, and say what you
would change in the class to switch from one to the other. Two sentences is enough.

    - a situation where that would be the right call would be when the key fields are actually what identify
    the thing being tracked, like when two people counting the same slot, are counting the same thing. It would make
    sense to keep one reading and throw out the other
    - a situation where that would be bug is if you actually needed to preserve each individual reading instead of 
    throwing out duplicates


src folder contains the cpp files, while include contain header files
