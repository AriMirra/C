cmake_minimum_required(VERSION 3.6)
project(CFromJava)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Exercise1/Provider.c Exercise1/Provider.h Exercise1/Manufacturer.c Exercise1/Manufacturer.h Exercise1/Appliance.c Exercise1/Appliance.h Exercise1/DataBase.c Exercise1/DataBase.h Exercise1/Invoice.c Exercise1/Invoice.h Exercise1/Label.c Exercise1/Label.h Exercise1/ShoppingCart.c Exercise1/ShoppingCart.h Exercise1/ShoppingCartLine.c Exercise1/ShoppingCartLine.h Exercise1/InvoiceLine.c Exercise1/InvoiceLine.h Exercise2/Product.c Exercise2/Product.h Exercise2/Provider.c Exercise2/Provider.h Exercise2/Manufacturer.c Exercise2/Manufacturer.h Exercise2/SalesLine.c Exercise2/SalesLine.h Exercise2/Sales.c Exercise2/Sales.h Exercise2/User.c Exercise2/User.h Exercise2/ProductTable.c Exercise2/ProductTable.h Exercise1/AdminMenu.c Exercise1/AdminMenu.c Util/ScanUtil.c Util/ScanUtil.h Exercise1/ClientMenu.c)
add_executable(CFromJava ${SOURCE_FILES})