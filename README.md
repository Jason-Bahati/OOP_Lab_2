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


Lab 2 Hierarchy questions
1.) PhysicalGood has real code in it and still cannot be built. Why is that the right call? What would
break if you made it concrete and let somebody write new PhysicalGood(...) ?
    
    - Because it inherits Category() and HandlingFee() StockItem, which are pure virtual functions
    it's the right call because PhysicalGood doesn't know what kind of item it is. If it were concrete,
    someone could make a random physical good that misrepresents what it actually is

2.)Your program has two diamonds and only one of them is filled. Explain both. For each
relationship, say who creates the object and what survives what. Then answer the harder half: if Add
were changed so that Shop took a Sku, a name, a price, and a quantity and built the record itself,
which diamond would change, and would that be an improvement or a mistake?

    - Shops holds StockItem pointers - hollow diamond - aggregation
    main builds every record with new and hand the pointer to Add. The record exists before shop sees it
    and would still be valid if shop were deleted
    - StockItem holds StockMovement objects - filled diamond, composition.
    A movemnet is only ever built inside Receive/Release, nothing outside the record ever holds one 
    and since history is a vector of StockMovement objects, by value every movement is destroyed along with its
    record

