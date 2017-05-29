set(SOURCE_FILES Product.c Product.h Provider.c Provider.h Manufacturer.c Manufacturer.h SalesLine.c SalesLine.h Sales.c Sales.h User.c User.h ProductTable.c ProductTable.h)
add_library(exercise2 ${SOURCE_FILES})
add_executable(exercise2_main Main2.c)
target_link_libraries(exercise2_main exercise2)