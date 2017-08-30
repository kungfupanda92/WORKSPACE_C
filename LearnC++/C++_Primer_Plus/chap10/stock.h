/*******************************************************************************
 * @file    stock.h
 * @author  Cody
 * @version V1.0
 * @date    
 * @brief   Stock class interface
 *
 ******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STOCK_H__
#define __STOCK_H__

/* Includes ------------------------------------------------------------------*/

#include <string>

/* Exported define -----------------------------------------------------------*/

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}
public:
    //declare two constructor
    Stock();
    Stock(const std::string &co, long n, double pr);
    ~Stock();
    
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif