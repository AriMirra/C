set(SOURCE_FILES Product.c Product.h Provider.c Provider.h Manufacturer.c Manufacturer.h User.c User.h DataBase.c DataBase.h Invoice.c Invoice.h InvoiceLine.c InvoiceLine.h Cart.c Cart.h CartLine.c CartLine.h Accessory.c Accessory.h Camera.c Camera.h AdminMenu.c ClientMenu.c UserMenu.c)
add_library(exercise2 ${SOURCE_FILES})
add_executable(exercise2_main Main2.c)
target_link_libraries(exercise2_main exercise2 Util)