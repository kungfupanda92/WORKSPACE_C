/*******************************************************************************
 * @file    stock.cpp
 * @author  Cody
 * @version V1.0
 * @date    
 * @brief   implementing the Stock class
 *
 ******************************************************************************/
#include <iostream>
#include "stock.h"
Stock::Stock() //Default contructor
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const std::string &co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative"
                << company << "share set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    set_tot();
}
Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}
void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative."
                << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0)
    {
        std::cout << "Number of shares purchased can't be negative."
                << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        std::cout << "You can't shell more than you have!"
            << " Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
void Stock::show()
{
    using std::cout;
    using std::ios_base;
    //Set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    std::cout << "Company: " << company
            << "    Shares: " << shares << std::endl
            << "    Share price: $" << share_val;
    //Set format to #.##
    cout.precision(2);
    cout << "   Total Worth: $" << total_val << std::endl;
    //Restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}